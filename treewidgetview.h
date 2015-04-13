#ifndef TREEWIDGETVIEW_H
#define TREEWIDGETVIEW_H

#include "abstractwidgetview.h"

class TreeWidgetView : public AbstractWidgetView
{
public:
    TreeWidgetView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // TREEWIDGETVIEW_H
