#include "radiobutton.h"



RadioButton::RadioButton(QPoint&position, int numberOfWidget):AbstractButton(position, *(new QSize(82,17)))
{
    _name = QString("RadioButton_").append(QString::number(numberOfWidget));
    _text = "RadioButton";
}

void RadioButton::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QRadioButton");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeEndElement();
}

void RadioButton::drawSelf(QGraphicsScene &scene)
{
    RadioButtonView * view = new RadioButtonView(this);
    scene.addItem(view);
}


