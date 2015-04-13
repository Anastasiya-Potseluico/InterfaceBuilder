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
#include "graphicsview.h"
#include "label.h"
#include "calendar.h"
#include "tablewidget.h"
#include "listwidget.h"
#include "treewidget.h"
#include "spinbox.h"
#include "progressbar.h"

enum FIGURE_LOCATION {left_up, left_down, center_up, center_down, near_center, left_center, right_center, right_up, right_down, none};
enum FIGURE_NAME {radio_button, push_button, check_box, combo_box, line_edit, label, graphics_view, calendar, table_widget, list_widget, tree_widget, progress_bar, spin_box};

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

    FIGURE_LOCATION getLocation(std::vector<cv::Point> &figureContainer, std::vector<cv::Point> &figureInner);
    bool isInsideContour(const std::vector<cv::Point> & contourContainer,const std::vector<cv::Point> & checkingContour);
    bool findPushButtons(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    bool findRadioButtons();
    bool findComboBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    bool findCheckBoxes(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    bool findLineEdits(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    bool findSpinBoxes(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures);
    bool findListWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures);
    bool findTreeWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerRects, std::vector<cv::Point> &buttonInnerCircle);
    bool findTableWidgets(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures);
    bool findLabels(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    bool findProgressBars(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures);
    bool findCalendars(std::vector<cv::Point> &buttonFrame, QList<std::vector<cv::Point> > &buttonInnerFigures);
    bool findGraphicsViews(std::vector<cv::Point> &buttonFrame, std::vector<cv::Point> &buttonInnerFigure);
    QList<std::vector<cv::Point> > getInnerShapesList(std::vector<cv::Point> &contour, QList<std::vector<cv::Point> > & list);

};

#endif // GEOMETRICALOBJECTSCOLLECTOR_H
