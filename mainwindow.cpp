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

/*Слот для показа отображений интерфейсов*/
void MainWindow::showInterface()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-5, -5, 1500,1500);
    scene->addRect(0,0,1200,900,QPen(Qt::black, 1),QBrush());
    QGraphicsScene* scene1 = new QGraphicsScene(this);
    scene1->setSceneRect(-5, -5, 1500,1500);
    scene1->addRect(0,0,1200,900,QPen(Qt::black, 1),QBrush());
    switch (ui->interfaceWidget->currentIndex())
    {
    case 0:
        ui->interfaceView->setScene(scene1);
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
        ui->interfaceView_s->setScene(scene1);
        getRealInterface(*scene1);
        break;
    }
}

void MainWindow::drawWidgets(QGraphicsScene &scene)
{
    AbstractWidget* window = _recognizer->getMainWindow();
    window->drawSelf(scene);
}

void MainWindow::getRealInterface(QGraphicsScene &scene)
{
    //Создать файл формата xml

    QFile file("temp");
    bool ok =  file.open(QIODevice::WriteOnly);
    int e = file.OpenError;
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("ui");
    xmlWriter.writeAttribute("version","4.0");
    AbstractWidget* window = _recognizer->getMainWindow();
    window->writeSelfIntoFile(xmlWriter);

    xmlWriter.writeEndElement();

    //Преобразовать полученный файл в виджет и поместить его на сцену
}
