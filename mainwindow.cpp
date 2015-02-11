#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(chooseAction(QAction*)));
    connect(ui->interfaceWidget, SIGNAL(currentChanged(int)), this, SLOT(showInterface()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

/*Слот для обработки выбора одного пункта из меню*/
void MainWindow::chooseAction(QAction *action)
{
    cv::Mat loaded;
    if (action->objectName()=="loadImageAction")
    {
        loaded = loadImage();
        _recognizer = new ImageRecognizer(source);
        _recognizer->recognizeWidgets();
    }
    else if (action->objectName()=="loadPSDAction")
    {
    }
    else if (action->objectName()=="generateUIAction")
    {
    }
}

/*Метод для загрузки изображения*/
cv::Mat MainWindow::loadImage()
{
    QString filePath;
    filePath = QFileDialog::getOpenFileName(this,"Open picture",QString(),"Picture(*.png *.jpeg *.bmp)");
    cv::Mat source = cv::imread(filePath.toStdString().c_str());
    return source;
}

/*Метод для загрузки PSD-файла*/
void MainWindow::loadPSD()
{
}

/*Слот для показа отображений интерфейсов*/
void MainWindow::showInterface()
{
    switch (ui->interfaceWidget->currentIndex())
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    }
}
