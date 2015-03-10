#ifndef IMAGERECOGNIZER_H
#define IMAGERECOGNIZER_H

#include <QList>
#include "abstractwidget.h"
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "geometricalobjectscollector.h"

#include "typeinfo"

class ImageRecognizer
{
public:
    ImageRecognizer();
    ImageRecognizer(cv::Mat source);
    QList<AbstractWidget> recognizeWidgets();

private:
    cv::Mat _inputImage;
    QList<AbstractWidget*> _widgets;
    QList<std::vector<cv::Point> > _triangles;
    QList<std::vector<cv::Point> > _rectangles;
    QList<std::vector<cv::Point> > _circles;
    QList<QString> _errors;
    GeometricalObjectsCollector  _collector; //Класс для сбора геометрических фигур в виджеты


    void findGeometricalFeatures();
    bool isTriangle(std::vector<cv::Point> & contour);
    bool isRectangle(std::vector<cv::Point> & contour);
    bool isEllipse(std::vector<cv::Point> & contour);
    double angle(cv::Point pt1, cv::Point pt2, cv::Point pt0);
    void collectFeaturesIntoWidgets();
    bool isInsideContour(const std::vector<cv::Point> & checkingContour,const std::vector<cv::Point> & contourContainer);
};

#endif // IMAGERECOGNIZER_H
