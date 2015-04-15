#ifndef LISTWIDGETVIEW_H
#define LISTWIDGETVIEW_H

#include "abstractwidgetview.h"

class ListWidgetView : public AbstractWidgetView
{
public:
    ListWidgetView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // LISTWIDGETVIEW_H
