#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

class AbstractItemWidget : public AbstractWidget
{
public:
    AbstractItemWidget(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;

protected:
    bool _autoScroll;
    bool _tabKeyNavigate;

    QString writeSelfIntoFile(QFile&file);
};

#endif // ABSTRACTITEMWIDGET_H
