#include "treewidget.h"

TreeWidget::TreeWidget(QPoint &position, int numberOfWidget): AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TreeWidget_").append(QString::number(numberOfWidget));
    _headerVisible = true;
    _columnCount = 1;
}

void TreeWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QTreeWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("attribute");
    xmlWriter.writeAttribute("name","headerVisible");
    xmlWriter.writeTextElement("bool",_headerVisible ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","columnCount");
    xmlWriter.writeTextElement("number",QString::number(_columnCount));
    xmlWriter.writeEndElement();

    int i;
    for(i = 0; i < _columnCount; i++)
    {
        xmlWriter.writeStartElement("column");
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","text");
        xmlWriter.writeStartElement("string");
        xmlWriter.writeAttribute("notr","true");
        xmlWriter.writeCharacters(QString::number(i+1));
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
}

void TreeWidget::drawSelf(QGraphicsScene &scene)
{
    TreeWidgetView * view = new TreeWidgetView(this);
    scene.addItem(view);
}
