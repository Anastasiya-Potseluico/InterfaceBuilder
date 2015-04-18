#include "listwidget.h"

ListWidget::ListWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("ListWidget_").append(QString::number(numberOfWidget));
    _sortingEnabled = true;
    _wordWrap = true;
}

void ListWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QListWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","sortingEnabled");
    xmlWriter.writeTextElement("bool",_sortingEnabled ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void ListWidget::drawSelf(QGraphicsScene &scene)
{
    ListWidgetView * view = new ListWidgetView(this);
    scene.addItem(view);
}

