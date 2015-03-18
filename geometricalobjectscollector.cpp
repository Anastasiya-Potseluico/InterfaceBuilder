#include "geometricalobjectscollector.h"

GeometricalObjectsCollector::GeometricalObjectsCollector()
{
    _widgetCounts.insert(radio_button,0);
    _widgetCounts.insert(push_button,0);
    _widgetCounts.insert(check_box,0);
    _widgetCounts.insert(combo_box,0);
    _widgetCounts.insert(line_edit,0);
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
    for(i = 0; i < _rectangles.size(); i++)
    {
        roundsList = shapeCountInside(_rectangles[i], _rounds);
        rectanglesList = shapeCountInside(_rectangles[i], _rectangles);
        trianglesList = shapeCountInside(_rectangles[i], _triangles);

        if(trianglesList.size() == 1 && !rectanglesList.size() && !roundsList.size())
        {
            findComboBoxes(_rectangles[i],trianglesList[0]);
            findLineEdits(_rectangles[i],trianglesList[0]);
        }
        else if (!trianglesList.size() && rectanglesList.size()==1 && !roundsList.size())
        {
            findPushButtons(_rectangles[i],rectanglesList[0]);
            findCheckBoxes(_rectangles[i],rectanglesList[0]);
        }
        else if (!trianglesList.size() && !rectanglesList.size() && roundsList.size() == 1)
        {

        }
    }
    return _widgets;
}

/* Метод для нахождения расположения одного контура в другом*/
FIGURE_LOCATION GeometricalObjectsCollector::getLocation(std::vector<cv::Point> &figure1,
                                                         std::vector<cv::Point> &figure2)
{
    //Найти центр первого контура
    cv::Moments moment1 = moments(figure1, false);
    cv::Point2f p1 = cv::Point2f( moment1.m10/moment1.m00 , moment1.m01/moment1.m00 );
    //Найти центр второго контура
    cv::Moments moment2 = moments(figure2, false);
    cv::Point2f p2 = cv::Point2f( moment2.m10/moment2.m00 , moment2.m01/moment2.m00 );
    //float distance = cv::pointPolygonTest(list.at(i),p,true);

    float differenceX, differenceY;
    if(isInsideContour(figure1, figure2)) {
        differenceX = p1.x - p2.x;
        differenceY = p1.y - p2.y;
        if(abs(differenceX) < 10 && abs(differenceY) < 10) return center;
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
bool GeometricalObjectsCollector::isInsideContour(const std::vector<cv::Point> &checkingContour, const std::vector<cv::Point> &contourContainer)
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
void GeometricalObjectsCollector::findPushButtons(std::vector<cv::Point> &buttonFrame,std::vector<cv::Point> &buttonInnerFigure)
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
void GeometricalObjectsCollector::findRadioButtons()
{
    int i;
    int radioButtonCount;
    int roundCountInside,
        rectangleCountInside,
        triangleCountInside;

    QList<std::vector<cv::Point> > roundsList;
    for(i = 0; i < _rounds.size(); i++)
    {
        roundsList = shapeCountInside(_rounds[i], _rounds);
        roundCountInside = roundsList.size();
        rectangleCountInside = shapeCountInside(_rounds[i], _rectangles).size();
        triangleCountInside = shapeCountInside(_rounds[i], _triangles).size();
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
void GeometricalObjectsCollector::findComboBoxes(std::vector<cv::Point> &buttonFrame,std::vector<cv::Point> &buttonInnerFigure)
{
    int comboBoxCount;
    if(getLocation(buttonFrame,buttonInnerFigure) == (right_center || right_up || right_down))
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
    }
}

/* Метод для выделения чекбоксов из геометрических объектов*/
void GeometricalObjectsCollector::findCheckBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int checkBoxCount;
    if(getLocation(buttonFrame, buttonInnerFigure) == (center || center_up || center_down || left_center ||right_center))
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
    }
}

void GeometricalObjectsCollector::findLineEdits(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int lineEditCount;
    if(getLocation(buttonFrame,buttonInnerFigure) == (left_center || left_up || left_down))
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
    }
}

void GeometricalObjectsCollector::findSpinBoxes()
{
}

void GeometricalObjectsCollector::findListWidgets()
{
}

void GeometricalObjectsCollector::findTreeWidgets()
{
}

void GeometricalObjectsCollector::findTableWidgets()
{
}

void GeometricalObjectsCollector::findLabels(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int labelCount;
    if(getLocation(buttonFrame, buttonInnerFigure) == (left_down || left_up || left_center))
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        labelCount = _widgetCounts.value(label);
        labelCount+=1;
        _widgetCounts.insert(label,labelCount);
        AbstractWidget * label = new Label(center,labelCount);
        _widgets.append(label);
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
    }
}

void GeometricalObjectsCollector::findProgressBars()
{
}

void GeometricalObjectsCollector::findCalendars()
{
}

void GeometricalObjectsCollector::findGraphicsViews(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure)
{
    int graphicsViewCount;
    if(getLocation(buttonFrame, buttonInnerFigure) == right_down)
    {
        cv::Moments moment = moments(buttonFrame, false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint center(p.x,p.y);
        graphicsViewCount = _widgetCounts.value(graphics_view);
        graphicsViewCount+=1;
        _widgetCounts.insert(graphics_view,graphicsViewCount);
        AbstractWidget * view = new PushButton(center,graphicsViewCount);
        _widgets.append(view);
        _rectangles.removeOne(buttonFrame);
        _rectangles.removeOne(buttonInnerFigure);
    }
}

QList<std::vector<cv::Point> > GeometricalObjectsCollector::shapeCountInside(std::vector<cv::Point> &contour, QList<std::vector<cv::Point> > & list)
{
    int i;
    QList<std::vector<cv::Point> > shapesInside;
    for(i = 0; i < list.size(); i++)
    {
        if(isInsideContour(list[i], contour) && list[i] != contour)
        {
            shapesInside.append(list[i]);
        }
    }
    return shapesInside;
}


