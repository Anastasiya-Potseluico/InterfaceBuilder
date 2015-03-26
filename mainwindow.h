#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "imagerecognizer.h"
#include "psdparser.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include "abstractwidgetview.h"

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
    ImageRecognizer *_recognizer; // ����� �������������� �������� �� �����������.
    PSDParser *_parser; // ����� ������� �������.
    cv::Mat loadImage();
    void loadPSD();
    void drawWidgets(QGraphicsScene &scene);

private slots:
    void chooseAction(QAction * action);
    void showInterface();
};

#endif // MAINWINDOW_H
