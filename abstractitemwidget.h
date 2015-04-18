#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

class AbstractItemWidget : public AbstractWidget
{
public:
    AbstractItemWidget(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
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

protected:
    bool _autoScroll;
    bool _tabKeyNavigate;
};

#endif // ABSTRACTITEMWIDGET_H
