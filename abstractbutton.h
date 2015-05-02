#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QImage>
#include "abstractwidget.h"

class AbstractButton : public AbstractWidget
{
public:
    AbstractButton(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    virtual QString getClassname() = 0;

    virtual void setSettings(QMap<QString, QString> &settings)
    {
        AbstractWidget::setSettings(settings);
        QString tempString = settings.value("text");
        _text = tempString;
        tempString = settings.value("checkable");
        if(tempString == "true")
            _enabled = true;
        else
            _enabled = false;
        tempString = settings.value("isChecked");
        if(tempString == "true")
            _enabled = true;
        else
            _enabled = false;
    }

    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        AbstractWidget::writeSelfIntoFile(xmlWriter);

        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","text");
        xmlWriter.writeTextElement("string",_text);
        xmlWriter.writeEndElement();
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","checkable");
        xmlWriter.writeTextElement("bool",_checkable ? "true":"false");
        xmlWriter.writeEndElement();
        if(_checkable)
        {
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","checked");
            xmlWriter.writeTextElement("bool",_isChecked ? "true":"false");
            xmlWriter.writeEndElement();
        }
        // TODO QIcon
    }

protected:
    bool _checkable;
    bool _isChecked;
    QString _text;
    QImage _icon;
    void addWidgetsForSettings();


};

#endif // ABSTRACTBUTTON_H
