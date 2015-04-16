#include "combobox.h"
#include "abstractbutton.h"

ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractWidget(position,*(new QSize(69,22)))
{
    _name = QString("ComboBox_").append(QString::number(numberOfWidget));
    _currentIndex = -1;
    _isEditable = false;
}

void ComboBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QComboBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","editable");
    xmlWriter.writeTextElement("bool",_isEditable ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","currentIndex");
    xmlWriter.writeTextElement("number", QString::number(_currentIndex));
    xmlWriter.writeEndElement();

    if(_items.size()) {
        int i;
        for(i = 0; i < _items.size(); i++)
        {
            xmlWriter.writeStartElement("item");

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","text");
            xmlWriter.writeTextElement("string", _items.at(i));
            xmlWriter.writeEndElement();

            xmlWriter.writeEndElement();
        }
    }

    xmlWriter.writeEndElement();
}

void ComboBox::drawSelf(QGraphicsScene &scene)
{
    ComboBoxView * view = new ComboBoxView(this);
    scene.addItem(view);
}
