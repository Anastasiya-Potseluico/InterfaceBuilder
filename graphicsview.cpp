#include "graphicsview.h"

GraphicsView::GraphicsView(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(256,192)))
{
    _interactive = false;
    _verticalScrollPanel = as_needed;
    _horizontalScrollPanel = as_needed;
    _name = QString("GraphicsView").append(QString::number(numberOfWidget));
}

void GraphicsView::drawSelf(QGraphicsScene &scene)
{
    GraphicsViewView * view = new GraphicsViewView(this);
    scene.addItem(view);
}

void GraphicsView::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QGraphicsView");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","interactive");
    xmlWriter.writeTextElement("bool",_interactive ? "true":"false");
    xmlWriter.writeEndElement();

    QString scrolls;

    switch (_verticalScrollPanel)
    {
        case as_needed:
        {
            scrolls = "Qt::ScrollBarAsNeeded";
            break;
        }
        case always_on:
        {
            scrolls = "Qt::ScrollBarAlwaysOn";
            break;
        }
        case always_off:
        {
            scrolls = "Qt::ScrollBarAlwaysOff";
            break;
        }
    }

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","verticalScrollBarPolicy");
    xmlWriter.writeTextElement("enum",scrolls);
    xmlWriter.writeEndElement();

    switch (_horizontalScrollPanel)
    {
        case as_needed:
        {
            scrolls = "Qt::ScrollBarAsNeeded";
            break;
        }
        case always_on:
        {
            scrolls = "Qt::ScrollBarAlwaysOn";
            break;
        }
        case always_off:
        {
            scrolls = "Qt::ScrollBarAlwaysOff";
            break;
        }
    }

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","horizontalScrollBarPolicy");
    xmlWriter.writeTextElement("enum",scrolls);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

}
