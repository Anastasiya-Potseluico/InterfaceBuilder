#include "tablewidget.h"

TableWidget::TableWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TableWidget_").append(QString::number(numberOfWidget));
    _showGrid = true;
    _rowCount = 0;
    _columnCount = 0;
}

void TableWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QTableWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","showGrid");
    xmlWriter.writeTextElement("bool",_showGrid ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","rowCount");
    xmlWriter.writeTextElement("number",QString::number(_rowCount));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","columnCount");
    xmlWriter.writeTextElement("number",QString::number(_columnCount));
    xmlWriter.writeEndElement();

    int i;
    for(i = 0; i < _rowCount; i++)
    {
        xmlWriter.writeEmptyElement("row");
    }

    for(i = 0; i < _columnCount; i++)
    {
        xmlWriter.writeEmptyElement("column");
    }

    xmlWriter.writeEndElement();
}

void TableWidget::drawSelf(QGraphicsScene &scene)
{
    TableWidgetView * view = new TableWidgetView(this);
    scene.addItem(view);
}
