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
FIGURE_LOCATION GeometricalObjectsCollector::getLocation(std::vector<cv::Point> &figure1,
                                                         std::vector<cv::Point> &figure2)
{

    //����� ����� ������� �������
    cv::Moments moment1 = moments(figure1, false);
    cv::Point2f p1 = cv::Point2f( moment1.m10/moment1.m00 , moment1.m01/moment1.m00 );
    //����� ����� ������� �������
    cv::Moments moment2 = moments(figure2, false);
    cv::Point2f p2 = cv::Point2f( moment2.m10/moment2.m00 , moment2.m01/moment2.m00 );
    //float distance = cv::pointPolygonTest(list.at(i),p,true);


    //����� ������� ��������
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
