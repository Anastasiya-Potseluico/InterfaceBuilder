#include "geometricalobjectscollector.h"

GeometricalObjectsCollector::GeometricalObjectsCollector()
{
}

/* ����������� ��������� �� ���� ��� ������ � ������������� ��������������� ��������*/
GeometricalObjectsCollector::GeometricalObjectsCollector(QList<std::vector<cv::Point> >&rectangles,
                            QList<std::vector<cv::Point> >&triangles,
                            QList<std::vector<cv::Point> >&rounds)
{
    _rectangles = rectangles;
    _triangles = triangles;
    _rounds = rounds;
}

/* ����� ��� ����� �������������� ����� � ������� */
QList<AbstractWidget> GeometricalObjectsCollector::collectObjectsIntoWidgets()
{

}

/* ����� ��� ���������� ������������ ������ ������� � ������*/
FIGURE_LOCATION GeometricalObjectsCollector::getLocation(QList<std::vector> &figure1, QList<std::vector> &figure2)
{

}

/* ����� ��� ��������� ������ �� �������������� ��������*/
void GeometricalObjectsCollector::findPushButtons()
{
}

/* ����� ��� ��������� ����������� �� �������������� ��������*/
void GeometricalObjectsCollector::findRadioButtons()
{
}

/* ����� ��� ��������� ����������� �� �������������� ��������*/
void GeometricalObjectsCollector::findComboBoxes()
{
}

/* ����� ��� ��������� ��������� �� �������������� ��������*/
void GeometricalObjectsCollector::findCheckBoxes()
{
}
