#include "abstractwidget.h"

AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

QString AbstractWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    int h = 0;
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","geometry");
    xmlWriter.writeStartElement("rect");
    xmlWriter.writeTextElement("x",QString::number(this->_position.x()));
    xmlWriter.writeTextElement("y",QString::number(this->_position.y()));
    xmlWriter.writeTextElement("width",QString::number(this->_size.width()));
    xmlWriter.writeTextElement("height",QString::number(this->_size.height()));
    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

QPoint AbstractWidget::getPosition()
{
    QPoint returnedPoint(_position.x(),_position.y());
    return returnedPoint;
}

QSize AbstractWidget::getSize()
{
    QSize returnedSize(_size.width(), _size.height());
    return returnedSize;
}

void AbstractWidget::setPosition(QPoint &position)
{
    _position = position;
}
