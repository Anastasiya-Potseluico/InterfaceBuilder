#include "imagerecognizer.h"

ImageRecognizer::ImageRecognizer()
{
   // _inputImage = input;
}

/*����� ��� ��������������� ��������� �����������*/
void ImageRecognizer::prepareImage()
{
    //�������� ��������
    cv::cvtColor(_inputImage, _inputImage, CV_BGR2GRAY);
    //�������� ������ �����
    cv::Canny(_inputImage, _inputImage, 0, 50, 5);
}

std::vector ImageRecognizer::findGeometricalFeatures()
{

}

/*����� ��� �����������, �������� �� ������ ������������� */
bool ImageRecognizer::isTriangle(std::vector<cv::Point> & contour)
{
    return (approx.size() == 3);
}

/*����� ��� �����������, �������� �� ������ ��������������� */
bool ImageRecognizer::isRectangle(std::vector<cv::Point> & contour)
{
    if (contour.size() >= 4 && contour.size() <= 6)
    {
        // ���������� ����� �������.
        int vtc = contour.size();

        // ������� �������� ����� ����� ��������� �������.
        std::vector<double> cos;
        for (int j = 2; j < vtc+1; j++)
        {
            cos.push_back(angle(contour[j%vtc], contour[j-2], contour[j-1]));
        }

        // ����������� ��� �������� �� ����������.
        std::sort(cos.begin(), cos.end());

        // ����� ������������ � ����������� ��������.
        double mincos = cos.front();
        double maxcos = cos.back();

        // ��������� ������������ ������� ��� ��������������: 4 ������� � ������ ����.
        if (vtc == 4 && mincos >= -0.1 && maxcos <= 0.3)
            return true;
    }
    return false;
}

/*����� ��� �����������, �������� �� ������ �������� */
bool ImageRecognizer::isEllipse(std::vector<cv::Point> & contour)
{
    if(contour.size() > 6)
    {
        // Detect and label circles
        double area = cv::contourArea(contour);
        cv::Rect r = cv::boundingRect(contour);
        int radius = r.width / 2;

        if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)
            return true;
    }
    return false;
}

/*����� ��� ����������� ���� ����� ��������� pt0->pt1 � pt0->pt2 */
double ImageRecognizer::angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}
