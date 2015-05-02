#include "geometricalobjectscollector.h"


GeometricalObjectsCollector::GeometricalObjectsCollector()
{
    _widgetCounts.insert(radio_button,0);
    _widgetCounts.insert(push_button,0);
    _widgetCounts.insert(check_box,0);
    _widgetCounts.insert(combo_box,0);
    _widgetCounts.insert(line_edit,0);
    _widgetCounts.insert(label,0);
    _widgetCounts.insert(graphics_view,0);
    _widgetCounts.insert(calendar,0);
    _widgetCounts.insert(table_widget,0);
    _widgetCounts.insert(list_widget,0);
    _widgetCounts.insert(tree_widget,0);
    _widgetCounts.insert(spin_box,0);
    _widgetCounts.insert(progress_bar,0);
}

/* Конструктор принимает на вход три списка с распознанными геометрическими фигурами*/
GeometricalObjectsCollector::GeometricalObjectsCollector(QList<std::vector<cv::Point> >rectangles,
                            QList<std::vector<cv::Point> >triangles,
                            QList<std::vector<cv::Point> >rounds)
{
    _rectangles = rectangles;
    _triangles = triangles;
    _rounds = rounds;
}

/* Метод для сбора геометрических фигур в виджеты */
void GeometricalObjectsCollector::collectObjectsIntoWidgets()
{
    findRadioButtons();

    int i;
    QList<std::vector<cv::Point> > trianglesList;
    QList<std::vector<cv::Point> > rectanglesList;
    QList<std::vector<cv::Point> > roundsList;
    bool found = false;
    for(i = 0; i < _rectangles.size(); i++)
    {
        roundsList = getInnerShapesList(_rectangles[i], _rounds);
        rectanglesList = getInnerShapesList(_rectangles[i], _rectangles);
        trianglesList = getInnerShapesList(_rectangles[i], _triangles);

        if(trianglesList.size() == 1 && !rectanglesList.size() && !roundsList.size())
        {
            found = findComboBoxes(_rectangles[i],trianglesList[0]);
            if(!found)
            {
               found = findLineEdits(_rectangles[i],trianglesList[0]);
            }
        }
        else if (!trianglesList.size() && rectanglesList.size()==1 && !roundsList.size())
        {
            found = findPushButtons(_rectangles[i],rectanglesList[0]);
            if(!found)
            {
                found = findCheckBoxes(_rectangles[i],rectanglesList[0]);
            }
        }
        else if (!trianglesList.size() && !rectanglesList.size() && roundsList.size() == 1)
        {
            found = findLabels(_rectangles[i],roundsList[0]);
            if(!found)
            {
                found = findGraphicsViews(_rectangles[i],roundsList[0]);
            }

        }
        else if (!trianglesList.size() && rectanglesList.size()==4 && !roundsList.size())
        {
            found = findCalendars(_rectangles[i],rectanglesList);
            if(!found)
            {
                found = findTableWidgets(_rectangles[i],rectanglesList);
            }
        }
        else if (!trianglesList.size() && rectanglesList.size()==3 && !roundsList.size())
        {
            found = findListWidgets(_rectangles[i],rectanglesList);
        }
        else if (!trianglesList.size() && rectanglesList.size()==2 && roundsList.size() == 1)
        {
            found = findTreeWidgets(_rectangles[i],rectanglesList,roundsList[0]);
        }
        else if (!trianglesList.size() && rectanglesList.size()==2 && !roundsList.size())
        {
            found = findProgressBars(_rectangles[i],rectanglesList);
        }
        else if (trianglesList.size() == 2 && !rectanglesList.size() && !roundsList.size())
        {
            found = findSpinBoxes(_rectangles[i],trianglesList);
        }
        if(found)
        {
            i = -1; //Начинаем просмотр фигур сначала
            found = false;
        }
    }
    _mainWindow = new MainWindowContainer();
    _mainWindow->setWidgets(_widgets);
}

AbstractWidget *GeometricalObjectsCollector::getMainWindow()
{
    return _mainWindow;
}

/* Метод для нахождения расположения одного контура в другом*/
FIGURE_LOCATION GeometricalObjectsCollector::getLocation(std::vector<cv::Point> &figureContainer,
                                                         std::vector<cv::Point> &figureInner)
{
    //Найти центр первого контура
    cv::Moments moment1 = moments(figureContainer, false);
    cv::Point2f p1 = cv::Point2f( moment1.m10/moment1.m00 , moment1.m01/moment1.m00 );
    //Найти центр второго контура
    cv::Moments moment2 = moments(figureInner, false);
    cv::Point2f p2 = cv::Point2f( moment2.m10/moment2.m00 , moment2.m01/moment2.m00 );
    //float distance = cv::pointPolygonTest(list.at(i),p,true);

    float differenceX, differenceY;
    if(isInsideContour(figureContainer, figureInner)) {
        differenceX = p2.x - p1.x;
        differenceY = p2.y - p1.y;
        if(abs(differenceX) < 10 && abs(differenceY) < 10) return near_center;
        else if(differenceX < 0 && abs(differenceY) < 10) return left_center;
        else if (differenceX > 0 && abs(differenceY) < 10) return right_center;
        else if (abs(differenceX) < 10 && differenceY < 0) return center_up;
        else if (abs(differenceX) < 10 && differenceY > 0) return center_up;
        else if (differenceX < 0 && differenceY < 0) return left_up;
        else if (differenceX < 0 && differenceY > 0) return left_down;
        else if (differenceX > 0 && differenceY < 0) return right_up;
        else if (differenceX > 0 && differenceY > 0) return right_down;
    }
    else return none;
}

/* Метод для определения, находитсся ли один контур внутри другого*/
bool GeometricalObjectsCollector::isInsideContour(const std::vector<cv::Point> &contourContainer, const std::vector<cv::Point> &checkingContour)
{
    int i;
    float distance;
    for(i = 0; i < checkingContour.size(); i++)
    {
        distance = cv::pointPolygonTest(contourContainer,checkingContour.at(i),true);
        if(distance < 0 )
        {
            return false;
        }
    }
    return true;
}


/* Метод для выделения кнопок из геометрических объектов*/
bool GeometricalObjectsCollector::findPushButtons(std::vector<cv::Point> &buttonFrame,std::vector<cv::Point> &buttonInnerFigure)
{
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    bool isInRightCorner;
    if (currentLocation == right_down || currentLocation == right_center)
    {
        isInRightCorner = true;
    }
    if(isInRightCorner)
    {
        QPoint center = findWidgetCenter(buttonFrame,push_button);
        _widgets.append(new PushButton(center,_widgetCounts.value(push_button)));

        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
    }
}

/* Метод для выделения радиокнопок из геометрических объектов*/
bool GeometricalObjectsCollector::findRadioButtons()
{
    int i;
    int roundCountInside,
        rectangleCountInside,
        triangleCountInside;

    QList<std::vector<cv::Point> > roundsList;
    for(i = 0; i < _rounds.size(); i++)
    {
        roundsList = getInnerShapesList(_rounds[i], _rounds);
        roundCountInside = roundsList.size();
        rectangleCountInside = getInnerShapesList(_rounds[i], _rectangles).size();
        triangleCountInside = getInnerShapesList(_rounds[i], _triangles).size();
        if(roundCountInside == 1 && !rectangleCountInside && !triangleCountInside)
        {
            QPoint center = findWidgetCenter(roundsList[0],radio_button);
            _widgets.append(new RadioButton(center,_widgetCounts.value(radio_button)));
            _rounds.removeOne(_rounds[i]);
            removeUsedGeometricalPrimitives(_rounds, roundsList);
            i = -1;
        }
    }
}

/* Метод для выделения комбобоксов из геометрических объектов*/
bool GeometricalObjectsCollector::findComboBoxes(std::vector<cv::Point> &buttonFrame,std::vector<cv::Point> &buttonInnerFigure)
{
     FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    if(currentLocation == right_center
            || currentLocation == right_up
            || currentLocation == right_down)
    {
        QPoint center = findWidgetCenter(buttonFrame,combo_box);
        _widgets.append(new ComboBox(center,_widgetCounts.value(combo_box)));
        _rectangles.removeOne(buttonFrame);
        _triangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

/* Метод для выделения чекбоксов из геометрических объектов*/
bool GeometricalObjectsCollector::findCheckBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame, buttonInnerFigure);
    if(currentLocation == near_center
            || currentLocation == center_up
            || currentLocation == center_down
            || currentLocation == left_center
            || currentLocation == right_center)
    {
        QPoint center = findWidgetCenter(buttonFrame,check_box);
        _widgets.append(new CheckBox(center,_widgetCounts.value(check_box)));
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findLineEdits(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int lineEditCount;
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    if(currentLocation == left_center
            || currentLocation == left_up
            || currentLocation == left_down)
    {
        QPoint center = findWidgetCenter(buttonFrame,line_edit);
        _widgets.append(new LineEdit(center,_widgetCounts.value(line_edit)));

        _rectangles.removeOne(buttonFrame);
        _triangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findSpinBoxes(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerFigures[0]);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerFigures[1]);

    bool firstInRightSide = false;
    bool secondInRightSide = false;
    if( loc1 == right_up || loc1 == right_down || loc1 == right_center)
    {
        firstInRightSide = true;
    }
    if( loc2 == right_up || loc2 == right_down || loc2 == right_center)
    {
        secondInRightSide = true;
    }
    if(firstInRightSide && secondInRightSide)
    {
        QPoint center = findWidgetCenter(buttonFrame,spin_box);
        _widgets.append(new SpinBox(center,_widgetCounts.value(spin_box)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_triangles, buttonInnerFigures);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findListWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerFigures[0]);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerFigures[1]);
    FIGURE_LOCATION loc3 = getLocation(buttonFrame, buttonInnerFigures[2]);

    bool isLeftUpCorner = false;
    bool isRightUpCorner = false;
    bool isLeftDownCorner = false;
    bool isRightDownCorner = false;

    if( loc1 == left_up || loc2 == left_up || loc3 == left_up)
    {
        isLeftUpCorner = true;
    }
    if( loc1 == right_up || loc2 == right_up || loc3 == right_up)
    {
        isRightUpCorner = true;
    }
    if( loc1 == left_down || loc2 == left_down || loc3 == left_down)
    {
        isLeftDownCorner = true;
    }
    if( loc1 == right_down || loc2 == right_down || loc3 == right_down)
    {
        isRightDownCorner = true;
    }

    if(!(isLeftUpCorner && isRightUpCorner && isLeftDownCorner && isRightDownCorner))
    {
        QPoint center = findWidgetCenter(buttonFrame,list_widget);
        _widgets.append(new ListWidget(center,_widgetCounts.value(list_widget)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_rectangles, buttonInnerFigures);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findTreeWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerRects, std::vector<cv::Point> &buttonInnerCircle)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerCircle);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerRects[0]);
    FIGURE_LOCATION loc3 = getLocation(buttonFrame, buttonInnerRects[1]);

    bool isLeftUpCorner = false;
    bool isRightUpCorner = false;
    bool isLeftDownCorner = false;
    bool isRightDownCorner = false;

    if( loc1 == left_up)
    {
        isLeftUpCorner = true;
    }
    if( loc2 == right_up || loc3 == right_up)
    {
        isRightUpCorner = true;
    }
    if(loc2 == left_down || loc3 == left_down)
    {
        isLeftDownCorner = true;
    }
    if(loc2 == right_down || loc3 == right_down)
    {
        isRightDownCorner = true;
    }
    if( loc2 == left_up || loc3 == left_up)
    {
        isLeftUpCorner = false;
    }

    if(!(isRightUpCorner && isLeftDownCorner && isRightDownCorner) && isLeftUpCorner)
    {
        QPoint center = findWidgetCenter(buttonFrame,tree_widget);
        _widgets.append(new TreeWidget(center,_widgetCounts.value(tree_widget)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_rectangles, buttonInnerRects);
        _rounds.removeOne(buttonInnerCircle);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findTableWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerFigures[0]);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerFigures[1]);
    FIGURE_LOCATION loc3 = getLocation(buttonFrame, buttonInnerFigures[2]);
    FIGURE_LOCATION loc4 = getLocation(buttonFrame, buttonInnerFigures[3]);

    bool isLeftUpCorner = false;
    bool isRightUpCorner = false;

    int tableCount;

    if( loc1 == left_up || loc2 == left_up || loc3 == left_up || loc4 == left_up )
    {
        isLeftUpCorner = true;
    }
    if( loc1 == right_up || loc2 == right_up || loc3 == right_up || loc4 == right_up )
    {
        isRightUpCorner = true;
    }

    if(isLeftUpCorner && isRightUpCorner)
    {
        QPoint center = findWidgetCenter(buttonFrame,table_widget);
        _widgets.append(new TableWidget(center,_widgetCounts.value(table_widget)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_rectangles, buttonInnerFigures);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findLabels(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    if(currentLocation == left_down
            || currentLocation == left_up
            || currentLocation == left_center)
    {
        QPoint center = findWidgetCenter(buttonFrame,label);
        _widgets.append(new Label(center,_widgetCounts.value(label)));

        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findProgressBars(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerFigures[0]);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerFigures[1]);

    bool firstInRigthSide = false;
    bool secondInRigthSide = false;

    int calendarCount;

    if(loc1 == right_up ||  loc1 == right_down || loc1 == right_center)
    {
        firstInRigthSide = true;
    }
    if(loc2 == right_up ||  loc2 == right_down || loc2 == right_center)
    {
        secondInRigthSide = true;
    }

    if(! (firstInRigthSide && secondInRigthSide))
    {
        QPoint center = findWidgetCenter(buttonFrame,progress_bar);
        _widgets.append(new ProgressBar(center,_widgetCounts.value(progress_bar)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_rectangles, buttonInnerFigures);
        return true;
    }
    return false;

}

bool GeometricalObjectsCollector::findCalendars(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
    FIGURE_LOCATION loc1 = getLocation(buttonFrame, buttonInnerFigures[0]);
    FIGURE_LOCATION loc2 = getLocation(buttonFrame, buttonInnerFigures[1]);
    FIGURE_LOCATION loc3 = getLocation(buttonFrame, buttonInnerFigures[2]);
    FIGURE_LOCATION loc4 = getLocation(buttonFrame, buttonInnerFigures[3]);

    bool isLeftUpCorner = false;
    bool isLeftDownCorner = false;
    bool isRightUpCorner = false;
    bool isRightDownCorner = false;

    if( loc1 == left_up || loc2 == left_up || loc3 == left_up || loc4 == left_up )
    {
        isLeftUpCorner = true;
    }
    if( loc1 == left_down || loc2 == left_down || loc3 == left_down || loc4 == left_down )
    {
        isLeftDownCorner = true;
    }
    if( loc1 == right_up || loc2 == right_up || loc3 == right_up || loc4 == right_up )
    {
        isRightUpCorner = true;
    }
    if( loc1 == right_down || loc2 == right_down || loc3 == right_down || loc4 == right_down )
    {
        isRightDownCorner = true;
    }

    if(isLeftUpCorner && isLeftDownCorner && isRightUpCorner && isRightDownCorner)
    {
        QPoint center = findWidgetCenter(buttonFrame,calendar);
        _widgets.append(new Calendar(center,_widgetCounts.value(calendar)));

        _rectangles.removeOne(buttonFrame);
        removeUsedGeometricalPrimitives(_rectangles, buttonInnerFigures);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findGraphicsViews(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame, buttonInnerFigure);
    if(currentLocation == near_center
            || currentLocation == left_center
            || currentLocation == right_center
            || currentLocation == center_up
            || currentLocation == center_down)
    {
        QPoint center = findWidgetCenter(buttonFrame,graphics_view);
        _widgets.append(new GraphicsView(center,_widgetCounts.value(graphics_view)));
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

QList<std::vector<cv::Point> > GeometricalObjectsCollector::getInnerShapesList(std::vector<cv::Point> &contour, QList<std::vector<cv::Point> > & list)
{
    int i;
    QList<std::vector<cv::Point> > shapesInside;
    for(i = 0; i < list.size(); i++)
    {
        if(isInsideContour(contour, list[i]) && list[i] != contour)
        {
            shapesInside.append(list[i]);
        }
    }
    return shapesInside;
}

QPoint GeometricalObjectsCollector::findWidgetCenter(std::vector<cv::Point> &widgetFrame, FIGURE_NAME widgetType)
{
    cv::Moments moment = moments(widgetFrame, false);
    cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
    int  widgetCount = _widgetCounts.value(widgetType);
    widgetCount+=1;
    _widgetCounts.insert(widgetType,widgetCount);
     return QPoint(p.x,p.y);
}

void GeometricalObjectsCollector::removeUsedGeometricalPrimitives(QList<std::vector<cv::Point> >&containerList, QList<std::vector<cv::Point> > &removedList)
{
    for(int i = 0; i < removedList.size(); i++)
    {
        containerList.removeOne(removedList[i]);
    }
}
