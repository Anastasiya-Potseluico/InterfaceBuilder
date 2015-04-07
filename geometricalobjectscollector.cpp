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
}

/* Конструктор принимает на вход три списка с распознанными геометрическими фигурами*/
GeometricalObjectsCollector::GeometricalObjectsCollector(QList<std::vector<cv::Point> >&rectangles,
                            QList<std::vector<cv::Point> >&triangles,
                            QList<std::vector<cv::Point> >&rounds)
{
    _rectangles = rectangles;
    _triangles = triangles;
    _rounds = rounds;
}

/* Метод для сбора геометрических фигур в виджеты */
QList<AbstractWidget*> GeometricalObjectsCollector::collectObjectsIntoWidgets()
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
        if(found)
        {
            i = -1; //Начинаем просмотр фигур сначала
            found = false;
        }
    }
    return _widgets;
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
    int pushButtonCount;
    if(getLocation(buttonFrame, buttonInnerFigure) == right_down)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        pushButtonCount = _widgetCounts.value(push_button);
        pushButtonCount+=1;
        _widgetCounts.insert(push_button,pushButtonCount);
        AbstractWidget * button = new PushButton(center,pushButtonCount);
        _widgets.append(button);
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
    }
}

/* Метод для выделения радиокнопок из геометрических объектов*/
bool GeometricalObjectsCollector::findRadioButtons()
{
    int i;
    int radioButtonCount;
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
            cv::Moments moment = moments(_rounds[i], false);
            cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
            QPoint center(p.x,p.y);
            radioButtonCount = _widgetCounts.value(radio_button);
            radioButtonCount+=1;
            _widgetCounts.insert(radio_button,radioButtonCount);
            AbstractWidget * button = new RadioButton(center,radioButtonCount);
            _widgets.append(button);
            _rounds.removeOne(_rounds[i]);
            _rounds.removeOne(roundsList[0]);
            i = -1;
        }
    }
}

/* Метод для выделения комбобоксов из геометрических объектов*/
bool GeometricalObjectsCollector::findComboBoxes(std::vector<cv::Point> &buttonFrame,std::vector<cv::Point> &buttonInnerFigure)
{
    int comboBoxCount;
     FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    if(currentLocation == right_center
            || currentLocation == right_up
            || currentLocation == right_down)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        comboBoxCount = _widgetCounts.value(combo_box);
        comboBoxCount += 1;
        _widgetCounts.insert(combo_box,comboBoxCount);
        AbstractWidget *box = new ComboBox(center,comboBoxCount);
        _widgets.append(box);
        _rectangles.removeOne(buttonFrame);
        _triangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

/* Метод для выделения чекбоксов из геометрических объектов*/
bool GeometricalObjectsCollector::findCheckBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int checkBoxCount;
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame, buttonInnerFigure);
    if(currentLocation == near_center
            || currentLocation == center_up
            || currentLocation == center_down
            || currentLocation == left_center
            || currentLocation == right_center)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        checkBoxCount = _widgetCounts.value(check_box);
        checkBoxCount+=1;
        _widgetCounts.insert(check_box,checkBoxCount);
        AbstractWidget * box = new CheckBox(center,checkBoxCount);
        _widgets.append(box);
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
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        lineEditCount = _widgetCounts.value(line_edit);
        lineEditCount += 1;
        _widgetCounts.insert(line_edit,lineEditCount);
        AbstractWidget * edit = new LineEdit(center,lineEditCount);
        _widgets.append(edit);
        _rectangles.removeOne(buttonFrame);
        _triangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findSpinBoxes()
{
}

bool GeometricalObjectsCollector::findListWidgets()
{
}

bool GeometricalObjectsCollector::findTreeWidgets()
{
}

bool GeometricalObjectsCollector::findTableWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures)
{
}

bool GeometricalObjectsCollector::findLabels(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int labelCount;
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame,buttonInnerFigure);
    if(currentLocation == left_down
            || currentLocation == left_up
            || currentLocation == left_center)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        labelCount = _widgetCounts.value(label);
        labelCount+=1;
        _widgetCounts.insert(label,labelCount);
        AbstractWidget * labelWidget = new Label(center,labelCount);
        _widgets.append(labelWidget);
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findProgressBars()
{
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

    int calendarCount;

    if( loc1 == left_up || loc2 == left_up || loc3 == left_up || loc4 == left_up )
    {
        isLeftUpCorner = true;
    }
    else if( loc1 == left_down || loc2 == left_down || loc3 == left_down || loc4 == left_down )
    {
        isLeftDownCorner = true;
    }
    else  if( loc1 == right_up || loc2 == right_up || loc3 == right_up || loc4 == right_up )
    {
        isRightUpCorner = true;
    }
    else if( loc1 == right_down || loc2 == right_down || loc3 == right_down || loc4 == right_down )
    {
        isRightDownCorner = true;
    }

    if(isLeftUpCorner && isLeftDownCorner && isRightUpCorner && isRightDownCorner)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        calendarCount = _widgetCounts.value(calendar);
        calendarCount+=1;
        _widgetCounts.insert(calendar,calendarCount);
        AbstractWidget * calendarWidget = new Calendar(center,calendarCount);
        _widgets.append(calendarWidget);
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigures[0]);
        _rectangles.removeOne(buttonInnerFigures[1]);
        _rectangles.removeOne(buttonInnerFigures[2]);
        _rectangles.removeOne(buttonInnerFigures[3]);
        return true;
    }
    return false;
}

bool GeometricalObjectsCollector::findGraphicsViews(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int graphicsViewCount;
    FIGURE_LOCATION currentLocation = getLocation(buttonFrame, buttonInnerFigure);
    if(currentLocation == near_center
            || currentLocation == center_v
            || currentLocation == center_h
            || currentLocation == center_up
            || currentLocation == center_down)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        graphicsViewCount = _widgetCounts.value(graphics_view);
        graphicsViewCount+=1;
        _widgetCounts.insert(graphics_view,graphicsViewCount);
        AbstractWidget * view = new GraphicsView(center,graphicsViewCount);
        _widgets.append(view);
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


