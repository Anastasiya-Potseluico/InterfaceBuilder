#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtUiTools/QUiLoader>
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QUiLoader loader;

    QFile file("H://attack.ui");
        file.open(QFile::ReadOnly);

        QWidget *formWidget = loader.load(&file, this);
        file.close();
        formWidget->move(100,100);
        formWidget->show();

}

MainWindow::~MainWindow()
{

    delete ui;
}
