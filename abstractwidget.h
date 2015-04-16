#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>
#include <QGraphicsScene>
#include <QFile>
#include <QXmlStreamWriter>


/* ����� ������������ �������.
*/
class AbstractWidget
{
public:
    AbstractWidget(QPoint& position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    QPoint getPosition();
    QSize getSize();
    void setPosition(QPoint &position);
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","geometry");
            xmlWriter.writeStartElement("rect");
            xmlWriter.writeTextElement("x",QString::number(this->_position.x()));
            xmlWriter.writeTextElement("y",QString::number(this->_position.y()));
            xmlWriter.writeTextElement("width",QString::number(this->_size.width()));
            xmlWriter.writeTextElement("height",QString::number(this->_size.height()));
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","enabled");
            xmlWriter.writeTextElement("bool",_enabled ? "true":"false");
            xmlWriter.writeEndElement();
    }

protected:
    QSize _size; // ������ ������.
    QPoint _position; // ������� ������� �� ������� ����.
    QString _name; // ��� �������.
    bool _enabled; // ��������� �������.

};

#endif // ABSTRACTWIDGET_H
