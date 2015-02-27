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
    for(int i =0;i<_rounds.size()-1;i++)
        getLocation(_rounds[i+1],_rounds[i]);
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

/* ����� ��� �����������, ���������� �� ���� ������ ������ �������*/
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

