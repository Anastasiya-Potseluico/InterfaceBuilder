#include "checkbox.h"

CheckBox::CheckBox(QPoint &position, int numberOfWidget):AbstractButton(position,*(new QSize(70,17)))
{
    _tristate = false;
    _text = "CheckBox";
    _name = QString("CheckBox_").append(QString::number(numberOfWidget));
}

void CheckBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCheckBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","tristate");
    xmlWriter.writeTextElement("bool",_tristate ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void CheckBox::drawSelf(QGraphicsScene &scene)
{
    CheckBoxView * view = new CheckBoxView(this);
    scene.addItem(view);
}
