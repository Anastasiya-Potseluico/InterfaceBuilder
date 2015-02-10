#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "imagerecognizer.h"
#include "psdparser.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"

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
    ImageRecognizer _recognizer; // Класс распознавателя виджетов на изображении.
    PSDParser _parser; // Класс парсера макетов.
    void loadImage();
    void loadPSD();

private slots:
    void chooseAction(QAction * action);
};

#endif // MAINWINDOW_H
