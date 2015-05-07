#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

class AbstractItemWidget : public AbstractWidget
{
public:
    AbstractItemWidget(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    virtual QString getClassname() = 0;
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        AbstractWidget::setSettings(settings);
        QString tempString = settings.value("tabKeyNavigate");
        if(tempString == "true")
            this->_tabKeyNavigate = true;
        else
            this->_tabKeyNavigate = false;
        tempString = settings.value("autoScroll");
        if(tempString == "true")
            this->_autoScroll = true;
        else
            this->_autoScroll = false;
    }

    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        AbstractWidget::writeSelfIntoFile(xmlWriter);

        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","tabKeyNavigate");
        xmlWriter.writeTextElement("bool",_tabKeyNavigate ? "true":"false");
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","autoScroll");
        xmlWriter.writeTextElement("bool",_autoScroll ? "true":"false");
        xmlWriter.writeEndElement();
    }

    virtual void addWidgetsForSettings()
    {
        AbstractWidget::addWidgetsForSettings();

        QCheckBox *tabKeyNavigate = new QCheckBox();
        tabKeyNavigate->setText("Tab Key Navigate");
        tabKeyNavigate->setChecked(_tabKeyNavigate);
        tabKeyNavigate->setObjectName("tabKeyNavigate");


        QCheckBox *autoscroll = new QCheckBox();
        autoscroll->setText("Autoscroll");
        autoscroll->setChecked(_autoScroll);
        autoscroll->setObjectName("autoscroll");

        _settings.append(tabKeyNavigate);
        _settings.append(autoscroll);
    }

protected:
    bool _autoScroll;
    bool _tabKeyNavigate;

};

#endif // ABSTRACTITEMWIDGET_H
