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

/*���� ��� ��������� ������ ������ ������ �� ����*/
void MainWindow::chooseAction(QAction *action)
{
    if (action->objectName()=="loadImageAction")
    {
        loadImage();
    }
    else if (action->objectName()=="loadPSDAction")
    {
    }
    else if (action->objectName()=="generateUIAction")
    {
    }
}

/*����� ��� �������� �����������*/
void MainWindow::loadImage()
{
    QString filePath;
    filePath = QFileDialog::getOpenFileName(this,"Open picture",QString(),"Picture(*.png *.jpeg *.bmp)");
    if(!filePath.isEmpty())
    {
        cv::Mat source = cv::imread(filePath.toStdString().c_str());
        _recognizer = new ImageRecognizer(source);
        _recognizer->recognizeWidgets();
    }
}

/*����� ��� �������� PSD-�����*/
void MainWindow::loadPSD()
{
}

/*���� ��� ������ ����������� �����������*/
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
