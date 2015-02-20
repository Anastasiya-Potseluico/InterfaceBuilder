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
FIGURE_LOCATION GeometricalObjectsCollector::getLocation(QList<std::vector> &figure1, QList<std::vector> &figure2)
{

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
