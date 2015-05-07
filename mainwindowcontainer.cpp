#include "mainwindowcontainer.h"

MainWindowContainer::MainWindowContainer():AbstractWidget(*(new QPoint(0,0)),*(new QSize(256,192)))
{
    _windowTitle = "MainWindow";
    _name = "MainWindow";
    addWidgetsForSettings();
}

void MainWindowContainer::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeTextElement("class",_name);
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QMainWindow");
    xmlWriter.writeAttribute("name",_name);
    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","windowTitle");
    xmlWriter.writeTextElement("string",_windowTitle);
    xmlWriter.writeEndElement();


    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QWidget");
    xmlWriter.writeAttribute("name","centralWidget");
    //Сделать лейаут по сетке..... !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int i;
    for (i = 0; i < _widgets.size(); i++) {
        _widgets[i]->writeSelfIntoFile(xmlWriter);
    }

    //записать каждый виджет в файл

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

void MainWindowContainer::drawSelf(QGraphicsScene &scene)
{
    MainWindowView * mainWindow= new MainWindowView(this);
    scene.addItem(mainWindow);
    int i;
    for (i = 0; i < _widgets.size(); i++) {
        _widgets[i]->drawSelf(scene);
    }
}

void MainWindowContainer::setWidgets(QList<AbstractWidget *> widgets)
{
    if(widgets.size()!=0)
    {
        _widgets = widgets;
        _size = countWindowDimension();
    }
}

void MainWindowContainer::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    QString tempString = settings.value("windowTitle");
    _windowTitle = tempString;
    _settings.clear();
    addWidgetsForSettings();
}

QString MainWindowContainer::getClassname()
{
    return QString("MainWindow");
}

void MainWindowContainer::addWidgetsForSettings()
{
    _settings.clear();
    QLabel *labelName = new QLabel("Name Of Main Window");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QLabel *labelTitle = new QLabel("Window Title");
    QLineEdit *title = new QLineEdit();
    title->setObjectName("windowTitle");
    title->setText(_windowTitle);

    _settings.append(labelName);
    _settings.append(name);
    _settings.append(labelTitle);
    _settings.append(title);
}

QList<AbstractWidget *> MainWindowContainer::getWidgets()
{
    return _widgets;
}

QSize MainWindowContainer::countWindowDimension()
{
    int maxY;
    int maxX;
    int i;
    maxY = _widgets[0]->getPosition().y() + _widgets[0]->getSize().height();
    maxX = _widgets[0]->getPosition().x() + _widgets[0]->getSize().width();
    for(i = 0; i < _widgets.size(); i++)
    {
        if((_widgets[i]->getPosition().x() + _widgets[i]->getSize().width()) > maxX )
        {
            maxX = _widgets[i]->getPosition().x() + _widgets[i]->getSize().width();
        }
        if((_widgets[i]->getPosition().y() + _widgets[i]->getSize().height()) > maxY )
        {
            maxY = _widgets[i]->getPosition().y() + _widgets[i]->getSize().height();
        }
    }
    return QSize(maxX+30, maxY+30);
}
