#include "progressbar.h"

ProgressBar::ProgressBar(QPoint &position, int numberOfWidget) :AbstractWidget(position,*(new QSize(118,23)))
{
    _name = QString("ProgressBar_").append(QString::number(numberOfWidget));
    _textVisible = true;
    _value = 20;
    _invertedAppearance = false;
    _minValue = 0;
    _maxValue = 100;
}

void ProgressBar::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QProgressBar");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","textVisible");
    xmlWriter.writeTextElement("bool",_textVisible ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","invertedAppearance");
    xmlWriter.writeTextElement("bool",_invertedAppearance ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","value");
    xmlWriter.writeTextElement("number",QString::number(_value));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximum");
    xmlWriter.writeTextElement("number",QString::number(_maxValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimum");
    xmlWriter.writeTextElement("number",QString::number(_minValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

}

void ProgressBar::drawSelf(QGraphicsScene &scene)
{
    ProgressBarView * view = new ProgressBarView(this);
    scene.addItem(view);
}
