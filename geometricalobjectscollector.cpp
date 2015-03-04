#include "geometricalobjectscollector.h"

GeometricalObjectsCollector::GeometricalObjectsCollector()
{
    _widgetCounts.insert(radio_button,0);
    _widgetCounts.insert(push_button,0);
    _widgetCounts.insert(check_box,0);
    _widgetCounts.insert(combo_box,0);
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
    int countRadioButton = 0;
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
            QPoint* center = new QPoint(p.x,p.y);
            countRadioButton = _widgetCounts.value(radio_button);
            countRadioButton+=1;
            _widgetCounts.insert(radio_button,countRadioButton);
            RadioButton * button = new RadioButton(*center,countRadioButton);
            _widgets.append(button);
            _rounds.removeOne(_rounds[i]);
            _rounds.removeOne(roundsList[0]);
            i -= 2;
        }
    }
}

/* Метод для выделения комбобоксов из геометрических объектов*/
void GeometricalObjectsCollector::findComboBoxes()
{
    int i;
    int countComboBox;
    int roundCountInside,
        rectangleCountInside,
        triangleCountInside;
    QList<std::vector<cv::Point> > trianglesList;
    for(i = 0; i < _rectangles.size(); i++)
    {
        roundCountInside = shapeCountInside(_rectangles[i], _rounds).size();
        rectangleCountInside = shapeCountInside(_rectangles[i], _rectangles).size();
        trianglesList = shapeCountInside(_rectangles[i], _triangles);
        triangleCountInside = trianglesList.size();
        if(triangleCountInside == 1 && !rectangleCountInside && !roundCountInside )
        {
            if(getLocation(_rectangles[i],trianglesList[0]) == (right_center || right_up || right_down))
            {
                cv::Moments moment = moments(_rectangles[i], false);
                cv::Point2f p = cv::Point2f( moment.m10/moment.m00 , moment.m01/moment.m00 );
                QPoint* center = new QPoint(p.x,p.y);
                countComboBox = _widgetCounts.value(combo_box);
                countComboBox += 1;
                _widgetCounts.insert(radio_button,countComboBox);
                ComboBox * box = new ComboBox(*center,countComboBox);
                _widgets.append(box);
                _rectangles.removeOne(_rectangles[i]);
                _triangles.removeOne(trianglesList[0]);
                i --;
            }
        }
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


