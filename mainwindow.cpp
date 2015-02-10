#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(chooseAction(QAction*)));

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
}

/*����� ��� �������� PSD-�����*/
void MainWindow::loadPSD()
{
}
