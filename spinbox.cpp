#include "spinbox.h"

SpinBox::SpinBox(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(42,22)))
{
    _name = QString("SpinBox_").append(QString::number(numberOfWidget));
    _readOnly = false;
    _maxValue = 0;
    _minValue = 99;
    _singleStep = 1;
    _value = 0;
}

void SpinBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QSpinBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","readOnly");
    xmlWriter.writeTextElement("bool",_readOnly ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimum");
    xmlWriter.writeTextElement("number",QString::number(_minValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximum");
    xmlWriter.writeTextElement("number",QString::number(_maxValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","value");
    xmlWriter.writeTextElement("number",QString::number(_value));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","singleStep");
    xmlWriter.writeTextElement("number",QString::number(_singleStep));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void SpinBox::drawSelf(QGraphicsScene &scene)
{
    SpinBoxView * view = new SpinBoxView(this);
    scene.addItem(view);
}
