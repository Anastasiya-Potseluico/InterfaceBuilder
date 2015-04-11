#ifndef TABLEWIDGETVIEW_H
#define TABLEWIDGETVIEW_H

#include "abstractwidgetview.h"

class TableWidgetView : public AbstractWidgetView
{
public:
    TableWidgetView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // TABLEWIDGETVIEW_H
