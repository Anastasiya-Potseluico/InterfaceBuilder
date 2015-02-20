#include "geometricalobjectscollector.h"

GeometricalObjectsCollector::GeometricalObjectsCollector()
{
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
QList<AbstractWidget> GeometricalObjectsCollector::collectObjectsIntoWidgets()
{

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


    //Найти площади контуров
    float square1 = cv::contourArea(figure1);
    float square2 = cv::contourArea(figure2);
    float distance;
    if(square1 > square2) {
        distance = cv::pointPolygonTest(square1,p2,true);

    }
    else
    {

    }


}

/* Метод для выделения кнопок из геометрических объектов*/
void GeometricalObjectsCollector::findPushButtons()
{

}

/* Метод для выделения радиокнопок из геометрических объектов*/
void GeometricalObjectsCollector::findRadioButtons()
{
}

/* Метод для выделения комбобоксов из геометрических объектов*/
void GeometricalObjectsCollector::findComboBoxes()
{
}

/* Метод для выделения чекбоксов из геометрических объектов*/
void GeometricalObjectsCollector::findCheckBoxes()
{
}
