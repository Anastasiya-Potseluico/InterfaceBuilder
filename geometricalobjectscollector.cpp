#include "geometricalobjectscollector.h"

GeometricalObjectsCollector::GeometricalObjectsCollector()
{
    _widgetCounts.insert(radio_button,0);
    _widgetCounts.insert(push_button,0);
    _widgetCounts.insert(check_box,0);
}

/* Конструктор принимает на вход три списка с распознанными геометрическими фигурами*/
GeometricalObjectsCollector::GeometricalObjectsCollector(QList<std::vector<cv::Point> >&rectangles,
                            QList<std::vector<cv::Point> >&triangles,
                            QList<std::vector<cv::Point> >&rounds)
{
    _rectangles = rectangles;
    _triangles = triangles;
    _rounds = rounds;
    for(int i =0;i<_rounds.size()-1;i++)
        getLocation(_rounds[i+1],_rounds[i]);
}

/* Метод для сбора геометрических фигур в виджеты */
QList<AbstractWidget *> GeometricalObjectsCollector::collectObjectsIntoWidgets()
{
    findRadioButtons();
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
void GeometricalObjectsCollector::findPushButtons()
{

}

/* Метод для выделения радиокнопок из геометрических объектов*/
void GeometricalObjectsCollector::findRadioButtons()
{
    int i;
    int countRadioButton;
    int roundCountInside,
        rectangleCountInside,
        triangleCountInside;
    for(i = 0; i < _rounds.size(); i++)
    {
        roundCountInside = shapeCountInside(_rounds[i], _rounds);
        rectangleCountInside = shapeCountInside(_rounds[i], _rectangles);
        triangleCountInside = shapeCountInside(_rounds[i], _triangles);
        if(roundCountInside == 1 && !rectangleCountInside && !triangleCountInside)
        {
            cv::Moments moment = moments(_rounds[i], false);
            cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
            QPoint* center = new QPoint(p.x,p.y);
            countRadioButton = _widgetCounts.value(radio_button);
            _widgetCounts.insert(radio_button,countRadioButton++);
            RadioButton * button = new RadioButton(*center,countRadioButton++);
            _widgets.append(button);
            _rounds.removeOne(_rounds[i]);
            i --;
        }
    }
}

/* Метод для выделения комбобоксов из геометрических объектов*/
void GeometricalObjectsCollector::findComboBoxes()
{
    int i, j, count;
    float square1, square2;
    int rectanglecount = 0;
    for(i = 0; i < _rectangles.size(); i++)
    {
        for(j = 0; j < _rectangles.size() && j!=i; j++)
        {

        }
    }



    if(isInsideContour(_rounds[i], _rounds[j]) || isInsideContour(_rounds[j], _rounds[i]))
    {
        cv::Moments moment = moments(_rounds[i], false);
        cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
        QPoint* center = new QPoint(p.x,p.y);
        count = _widgetCounts.value(radio_button);
        _widgetCounts.insert(radio_button,count++);
        RadioButton * button = new RadioButton(*center,count++);
        _widgets.append(button);
        _rounds.removeOne(_rounds[i]);
        _rounds.removeOne(_rounds[j]);
        i = -1;
        j = -1;
    }
}

/* Метод для выделения чекбоксов из геометрических объектов*/
void GeometricalObjectsCollector::findCheckBoxes()
{

}

void GeometricalObjectsCollector::findLineEdits()
{
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

void GeometricalObjectsCollector::findLabels()
{
}

void GeometricalObjectsCollector::findProgressBars()
{
}

void GeometricalObjectsCollector::findCalendars()
{
}

void GeometricalObjectsCollector::findImageViews()
{
}

int GeometricalObjectsCollector::shapeCountInside(std::vector<cv::Point> &contour, QList<std::vector<cv::Point> > & list)
{
    int i;
    int sum_count = 0;
    for(i = 0; i < list.size(); i++)
    {
        if(isInsideContour(list[i], contour) && list[i] != contour)
        {
            sum_count+=1;
        }
    }
    return sum_count;
}


