#ifndef GEOMETRICALOBJECTSCOLLECTOR_H
#define GEOMETRICALOBJECTSCOLLECTOR_H
#include <QList>
#include <QMap>
#include "abstractwidget.h"
#include "opencv2/core/core.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "radiobutton.h"
#include "combobox.h"
#include "pushbutton.h"
#include "label.h"
#include "lineedit.h"
#include "checkbox.h"

enum FIGURE_LOCATION {left_up, left_down, center_up, center_down, center, left_center, right_center, right_up, right_down, none};
enum FIGURE_NAME {radio_button, push_button, check_box, combo_box, line_edit, label, graphics_view};

class GeometricalObjectsCollector
{
public:
    GeometricalObjectsCollector();
    GeometricalObjectsCollector(QList<std::vector<cv::Point> >&rectangles,
                                QList<std::vector<cv::Point> >&triangles,
                                QList<std::vector<cv::Point> >&rounds);
    QList<AbstractWidget*> collectObjectsIntoWidgets();

private:
    QList<std::vector<cv::Point> > _rectangles;
    QList<std::vector<cv::Point> > _triangles;
    QList<std::vector<cv::Point> > _rounds;
    QList<AbstractWidget*> _widgets;
    QMap<FIGURE_NAME,int> _widgetCounts;

    FIGURE_LOCATION getLocation(std::vector<cv::Point> &figure1, std::vector<cv::Point> &figure2);
    bool isInsideContour(const std::vector<cv::Point> & checkingContour,const std::vector<cv::Point> & contourContainer);
    void findPushButtons(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    void findRadioButtons();
    void findComboBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    void findCheckBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    void findLineEdits(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    void findSpinBoxes();
    void findListWidgets();
    void findTreeWidgets();
    void findTableWidgets();
    void findLabels(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    void findProgressBars();
    void findCalendars();
    void findGraphicsViews(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    QList<std::vector<cv::Point> > shapeCountInside(std::vector<cv::Point> &contour, QList<std::vector<cv::Point> > & list);

};

#endif // GEOMETRICALOBJECTSCOLLECTOR_H
