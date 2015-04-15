#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

class AbstractItemWidget : public AbstractWidget
{
public:
    AbstractItemWidget(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
protected:
    bool _autoScroll;
    bool _tabKeyNavigate;


};

#endif // ABSTRACTITEMWIDGET_H
