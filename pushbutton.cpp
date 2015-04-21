#include "pushbutton.h"

PushButton::PushButton(QPoint &position, int numberOfWidget) : AbstractButton(position,*(new QSize(75,23)))
{
    _defaultOn = false;
    _text = "PushButton";
    _flat = false;
    _checkable = false;
    _name = QString("PushButton_").append(QString::number(numberOfWidget));
}

void PushButton::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QPushButton");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","default");
    xmlWriter.writeTextElement("bool",_defaultOn ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","flat");
    xmlWriter.writeTextElement("bool",_flat ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

}

void PushButton::drawSelf(QGraphicsScene &scene)
{
    PushButtonView * view = new PushButtonView(this);
    scene.addItem(view);
}
