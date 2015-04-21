#include "mainwindowcontainer.h"

MainWindowContainer::MainWindowContainer(QList<AbstractWidget*> widgets)
{
    _widgets = widgets;
    _windowTitle = "MainWindow";
    _name = "MainWindow";
    _position = QPoint(0,0);
    _size = countWindowDimension();
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
    int i;
    for (i = 0; i < _widgets.size(); i++) {
        _widgets[i]->drawSelf(scene);
    }
}

QSize MainWindowContainer::countWindowDimension()
{

}
