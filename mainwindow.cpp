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
        _recognizer = new ImageRecognizer(loaded);
        _recognizer->recognizeWidgets();
        showInterface();

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
    filePath = QFileDialog::getOpenFileName(this,"Open picture",QString(),"Picture(*.png *.jpg *.bmp)");
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
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,900,900);
    switch (ui->interfaceWidget->currentIndex())
    {
    case 0:

        break;
    case 1:
        ui->schemeView_b->setScene(scene);
        drawWidgets(*scene);
        ui->schemeView_b->show();
        break;
    case 2:
        ui->shemeView_s->setScene(scene);
        drawWidgets(*scene);
        ui->shemeView_s->show();
        break;
    }
}

void MainWindow::drawWidgets(QGraphicsScene &scene)
{
    QList<AbstractWidget*> list = _recognizer->getWidgets();
    int size = list.size();
    for(int i =0; i<size; i++)
    {
        list[i]->drawSelf(scene);
    }
}
