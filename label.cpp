#include "label.h"


Label::Label(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(46,13)))
{
    _verticalAlignment = center_v;
    _horizontalAlignment = left;
    _name = QString("Label_").append(QString::number(numberOfWidget));
}

void Label::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLabel");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();

    QString alignment;
    switch (_verticalAlignment)
    {
        case top:
        {
            alignment = "Qt::AlignTop";
            break;
        }
        case center_v:
        {
            alignment = "Qt::AlignVCenter";
            break;
        }
        case bottom:
        {
            alignment = "Qt::AlignBottom";
            break;
        }
    }
    alignment.append("|");
    switch (_horizontalAlignment)
    {
        case left:
        {
            alignment.append("Qt::AlignLeft");
            break;
        }
        case center_h:
        {
            alignment.append("Qt::AlignHCenter");
            break;
        }
        case right:
        {
            alignment.append("Qt::AlignRight");
            break;
        }
        case justify:
        {
            alignment.append("Qt::AlignJustify");
            break;
        }
    }

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","alignment");
    xmlWriter.writeTextElement("set",alignment);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void Label::drawSelf(QGraphicsScene &scene)
{
    LabelView * view = new LabelView(this);
    scene.addItem(view);
}
