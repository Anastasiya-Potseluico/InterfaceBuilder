#include "imagerecognizer.h"
#include "pushbutton.h"

ImageRecognizer::ImageRecognizer()
{
}

ImageRecognizer::ImageRecognizer(cv::Mat source)
{
    _inputImage = source;
}

/*����� ��� ��������� �������������� ����� �� �����������*/
void ImageRecognizer::findGeometricalFeatures()
{
    cv::cvtColor(_inputImage, _inputImage, CV_BGR2GRAY);
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(_inputImage, contours,hierarchy, CV_RETR_TREE , CV_CHAIN_APPROX_SIMPLE);
    std::vector<cv::Point> approx;

    float square;
    for (int i = 0; i < contours.size(); i++)
    {
        // �������������� �������.
        cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
        square = cv::contourArea(contours[i],true);
        if(square > 0)
        {
            if (isTriangle(approx))
            {
                _triangles.append(contours[i]);
            }
            else if (isRectangle(approx)&& cv::contourArea(contours[i],true) > 0)
            {
                _rectangles.append(contours[i]);
            }
            else if (isEllipse(approx) && cv::contourArea(contours[i],true) > 0)
            {
                _circles.append(contours[i]);
            }
        }
    }
    //!!!!!!!!��������!!!! ����� ������!!!


    cv::Mat dst = cv::Mat::zeros(_inputImage.rows, _inputImage.cols, CV_8UC3);

     cv::Mat drawing = cv::Mat::zeros( _inputImage.rows, _inputImage.cols, CV_8UC3 );
      for( int i = 0; i< contours.size(); i++ )
         {
           cv::Scalar color( (rand()&255), (rand()&255), (rand()&255) );
           cv::drawContours( drawing, contours, i, color, 2, 8, hierarchy, 0, cv::Point() );
         }
      cv::namedWindow( "all", 1 );
         cv::imshow( "all", drawing );
    std::vector<cv::Rect> boundRect( _rectangles.size()*10 );
    for ( int i=0; i<_rectangles.size(); i++ ) {
             boundRect[i] = cv::boundingRect( cv::Mat(_rectangles[i]) );
                // random colour
                cv::Scalar color( (rand()&255), (rand()&255), (rand()&255) );
                cv::rectangle( dst, boundRect[i].tl(), boundRect[i].br(), color, 2, 8, 0 );

        }
    for ( int i=0; i<_triangles.size(); i++ ) {
                // random colour
                cv::Scalar color( (rand()&255), (rand()&255), (rand()&255) );
                cv::polylines( dst, _triangles[i], true, color, 2, 8, 0 );

        }
    for ( int i=0; i<_circles.size(); i++ ) {
        // random colour
        cv::Scalar color( (rand()&255), (rand()&255), (rand()&255) );
        cv::polylines( dst, _circles[i], true, color, 2, 8, 0 );
        }
        cv::namedWindow( "Components", 1 );
           cv::imshow( "Components", dst );
           //!!!!!!!!!!!!!!!

}

/*����� ��� �����������, �������� �� ������ ������������� */
bool ImageRecognizer::isTriangle(std::vector<cv::Point> &contour)
{
    return (contour.size() == 3);
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

QList<AbstractWidget> ImageRecognizer::recognizeWidgets()
{
    findGeometricalFeatures();
}

void ImageRecognizer::collectFeaturesIntoWidgets()
{
}

/*����� ��� ������������ ������ ������������ �������� � ������ �������� */
void ImageRecognizer::throwExtraContoursFromList(QList<std::vector<cv::Point> > &list)
{

    for(int i = 0;i<list.size();i++ )
    {
        float square = cv::contourArea(list.at(i),true);
        if(square < 0)
        {
            list.removeAt(i);
            i=-1;
        }
    }
}

void ImageRecognizer::throwExtraContours()
{
    throwExtraContoursFromList(_rectangles);
}

/* ����� ��� �����������, ���������� �� ���� ������ ������ �������*/
bool ImageRecognizer::isInsideContour(const std::vector<cv::Point> &checkingContour, const std::vector<cv::Point> &contourContainer)
{
    int i;
    float distance;
    for(i = 0; i < checkingContour.size(); i++)
    {
        distance = cv::pointPolygonTest(contourContainer,checkingContour.at(i),true);
        if(distance <= -2 )
        {
            return false;
        }
    }
    return true;
}

