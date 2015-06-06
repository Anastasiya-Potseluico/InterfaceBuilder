#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    prepareScenes();
    _correctForWriting = false;
    connect(ui->menuBar, SIGNAL(triggered(QAction*)), this, SLOT(chooseAction(QAction*)));
    connect(ui->interfaceWidget, SIGNAL(currentChanged(int)), this, SLOT(showInterface()));
    connect(ui->schemeView_b->scene(), SIGNAL(changed(QList<QRectF>)), this, SLOT(writeWidgetsIntoFile()));
    connect(ui->shemeView_s->scene(), SIGNAL(changed(QList<QRectF>)), this, SLOT(writeWidgetsIntoFile()));
    connect(ui->updateButton, SIGNAL(clicked()), this, SLOT(syncronizeInterface()));
    connect(ui->sliderScheme, SIGNAL(valueChanged(int)), this, SLOT(zoomScheme()));

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
        if(!loaded.empty())
        {
            _outputFileName = QFileDialog::getSaveFileName(this,"Сохранить готовый файл с интерфейсом",QString("output.ui"),"Interface(*.ui)");
            if( _outputFileName.isEmpty())
                _outputFileName = "temp.ui";

            _recognizer = new ShapeRecognizer(loaded);
            _recognizer->findGeometricalFeatures();
            _widgetsCollector = new GeometricalPrimitivesCollector(_recognizer->getRectangles(), _recognizer->getTriangles(), _recognizer->getRounds());
            _widgetsCollector->collectObjectsIntoWidgets();
            connectWidgetsWithSlot();
            showInterface();
        }
    }
}

/*Метод для загрузки изображения*/
cv::Mat MainWindow::loadImage()
{
    QString filePath;
    cv::Mat source;
    filePath = QFileDialog::getOpenFileName(this,"Открыть изображение",QString(),"Picture(*.png *.jpg *.bmp)");
    source = cv::imread(filePath.toStdString().c_str());
    _correctForWriting = true;
    QImage img (filePath);
    if(!img.isNull())
    {
        ui->startView->scene()->addPixmap(QPixmap::fromImage(img));
    }
    return source;
}

/*Слот для показа отображений интерфейсов*/
void MainWindow::showInterface()
{

    switch (ui->interfaceWidget->currentIndex())
    {
    case 0:
        getRealInterface(*ui->interfaceView->scene());
        ui->interfaceView->verticalScrollBar()->setValue(0);
        ui->interfaceView->horizontalScrollBar()->setValue(0);
        break;
    case 1:
        drawWidgets(*ui->schemeView_b->scene());
        ui->schemeView_b->verticalScrollBar()->setValue(0);
        ui->schemeView_b->horizontalScrollBar()->setValue(0);
        ui->schemeView_b->show();
        break;
    case 2:
        drawWidgets(*ui->shemeView_s->scene());
        getRealInterface(*ui->interfaceView_s->scene());
        ui->shemeView_s->verticalScrollBar()->setValue(0);
        ui->shemeView_s->horizontalScrollBar()->setValue(0);
        ui->interfaceView_s->verticalScrollBar()->setValue(0);
        ui->interfaceView_s->horizontalScrollBar()->setValue(0);
        ui->shemeView_s->show();
        ui->interfaceView_s->show();
        break;
    }
}

void MainWindow::validateSameWidgetNames()
{
    // Проверка на уникальность имен
    QList<AbstractWidget*> list = ((MainWindowContainer*)this->_widgetsCollector->getMainWindow())->getWidgets();
    int i, j;
    bool hasSameNames = false;
    QString sameName;
    _correctForWriting = true;
    for(i = 0; i < list.size()-1 && !hasSameNames; i++)
    {
        for(j = i+1; j < list.size() && !hasSameNames; j++)
        {
            if(list.at(i)->getName() == list.at(j)->getName())
            {
                hasSameNames = true;
                sameName = list.at(i)->getName();
                _correctForWriting = false;
            }
        }
    }
    if(hasSameNames)
    {
        QMessageBox msgBox;
        QString text = "Имена виджетов должны быть уникальны. Имеется повторящееся имя ";
        text.append(sameName);
        msgBox.setText(text);
        msgBox.exec();
    }
}

void MainWindow::writeWidgetsIntoFile()
{
    //Создать файл формата xml
    if(_recognizer != NULL && _widgetsCollector != NULL && _correctForWriting )
    {

            QFile file(_outputFileName);
            bool ok =  file.open(QIODevice::WriteOnly);
            if(!ok)
            {
                QMessageBox msgBox;
                QString text = "Невозможно открыть файл!";
                msgBox.setText(text);
                msgBox.exec();
            }
            AbstractWidget* window = _widgetsCollector->getMainWindow();
            if(window != NULL)
            {
                QXmlStreamWriter xmlWriter(&file);
                xmlWriter.setAutoFormatting(true);
                xmlWriter.writeStartDocument();

                xmlWriter.writeStartElement("ui");
                xmlWriter.writeAttribute("version","4.0");

                window->writeSelfIntoFile(xmlWriter);
                xmlWriter.writeEndElement();
            }
        }
    }


void MainWindow::drawWidgets(QGraphicsScene &scene)
{
    scene.clear();
    scene.addRect(0,0,1200,900,QPen(Qt::gray, 1, Qt::DashDotLine),QBrush());
    if(_recognizer != NULL && _widgetsCollector !=NULL)
    {
        AbstractWidget* window = _widgetsCollector->getMainWindow();
        window->drawSelf(scene);
    }
}

void MainWindow::getRealInterface(QGraphicsScene &scene)
{
    scene.clear();
    scene.addRect(0,0,1200,900,QPen(Qt::gray, 1, Qt::DashDotLine),QBrush());
    writeWidgetsIntoFile();
    //Преобразовать полученный файл в виджет и поместить его на сцену
    QUiLoader loader;
    QFile file(_outputFileName);
    file.open(QFile::ReadOnly);
    QWidget *myWidget = loader.load(&file, this);
    file.close();
    scene.addWidget(myWidget);
}

void MainWindow::syncronizeInterface()
{
    getRealInterface(*ui->interfaceView_s->scene());
}

void MainWindow::zoomScheme()
{
    int value = ui->sliderScheme->value();
    if(value < 50)
        ui->shemeView_s->scale(1.1,1.1);
    else
        ui->shemeView_s->scale(0.9, 0.9);
}

void MainWindow::prepareScenes()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    scene->setSceneRect(-5, -5, 1500,1500);
    scene->addRect(0,0,1200,900,QPen(Qt::gray, 1, Qt::DashDotLine),QBrush());

    QGraphicsScene* scene1 = new QGraphicsScene(this);
    scene1->setSceneRect(-5, -5, 1500,1500);
    scene1->addRect(0,0,1200,900,QPen(Qt::black, 1),QBrush());

    QGraphicsScene* scene2 = new QGraphicsScene(this);
    scene2->setSceneRect(-5, -5, 1500,1500);
    scene2->addRect(0,0,1200,900,QPen(Qt::black, 1),QBrush());

    QGraphicsScene* scene3 = new QGraphicsScene(this);
    scene3->setSceneRect(-5, -5, 1500,1500);
    scene3->addRect(0,0,1200,900,QPen(Qt::black, 1),QBrush());

    QGraphicsScene* scene4 = new QGraphicsScene(this);

    ui->setupUi(this);

    ui->schemeView_b->setScene(scene);
    ui->interfaceView->setScene(scene1);
    ui->shemeView_s->setScene(scene2);
    ui->interfaceView_s->setScene(scene3);

    ui->shemeView_s->verticalScrollBar()->setValue(0);
    ui->shemeView_s->horizontalScrollBar()->setValue(0);
    ui->interfaceView_s->verticalScrollBar()->setValue(0);
    ui->interfaceView_s->horizontalScrollBar()->setValue(0);
    ui->schemeView_b->horizontalScrollBar()->setValue(0);
    ui->schemeView_b->verticalScrollBar()->setValue(0);
    ui->interfaceView->verticalScrollBar()->setValue(0);
    ui->interfaceView->horizontalScrollBar()->setValue(0);
    ui->startView->setScene(scene4);
    ui->startView->verticalScrollBar()->setValue(0);
    ui->startView->horizontalScrollBar()->setValue(0);
    ui->startView->setInteractive(false);
}

void MainWindow::connectWidgetsWithSlot()
{
    QList<AbstractWidget*> list = ((MainWindowContainer*)this->_widgetsCollector->getMainWindow())->getWidgets();
    for(int i = 0; i < list.size(); i++ )
    {
        connect(list.at(i), SIGNAL(settingsChanged()), this, SLOT(validateSameWidgetNames()));
        connect(list.at(i), SIGNAL(settingsChanged()), this, SLOT(writeWidgetsIntoFile()));
    }
}
