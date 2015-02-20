#ifndef GEOMETRICALOBJECTSCOLLECTOR_H
#define GEOMETRICALOBJECTSCOLLECTOR_H
#include <QList>
#include "abstractwidget.h"
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

enum FIGURE_LOCATION {left_up, left_down, center, right_up, right_down, none};

class GeometricalObjectsCollector
{
public:
    GeometricalObjectsCollector();
    GeometricalObjectsCollector(QList<std::vector<cv::Point> >&rectangles,
                                QList<std::vector<cv::Point> >&triangles,
                                QList<std::vector<cv::Point> >&rounds);
    QList<AbstractWidget> collectObjectsIntoWidgets();

private:
    QList<std::vector<cv::Point> > _rectangles;
    QList<std::vector<cv::Point> > _triangles;
    QList<std::vector<cv::Point> > _rounds;
    QList<AbstractWidget> _widgets;

    FIGURE_LOCATION getLocation(QList<std::vector<cv::Point> > &figure1, QList<std::vector<cv::Point> > &figure2);
    void findPushButtons();
    void findRadioButtons();
    void findComboBoxes();
    void findCheckBoxes();

};

#endif // GEOMETRICALOBJECTSCOLLECTOR_H
