#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "shaperecognizer.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "abstractwidgetview.h"
#include <QXmlStreamWriter>
#include <QUiLoader>
#include <QScrollBar>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    Ui::MainWindow *ui;
    ShapeRecognizer *_recognizer; // Класс распознавателя виджетов на изображении.
    GeometricalPrimitivesCollector *_widgetsCollector;
    bool _correctForWriting;
    cv::Mat loadImage();
    void drawWidgets(QGraphicsScene &scene);
    void prepareScenes();
    void connectWidgetsWithSlot();

private slots:
    void chooseAction(QAction * action);
    void showInterface();
    void validateSameWidgetNames();
    void writeWidgetsIntoFile();
    void getRealInterface(QGraphicsScene &scene);
    void syncronizeInterface();

};

#endif // MAINWINDOW_H
