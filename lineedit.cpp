#include "lineedit.h"


LineEdit::LineEdit(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(113,20)))
{
    _name = QString("LineEdit_").append(QString::number(numberOfWidget));
    _text = QString("");
    _readOnly = false;
}

void LineEdit::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLineEdit");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","readOnly");
    xmlWriter.writeTextElement("bool",_readOnly ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void LineEdit::drawSelf(QGraphicsScene &scene)
{
    LineEditView * view = new LineEditView(this);
    scene.addItem(view);
}
