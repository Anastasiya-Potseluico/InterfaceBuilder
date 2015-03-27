#ifndef GRAPHICSVIEWVIEW_H
#define GRAPHICSVIEWVIEW_H

#include "abstractwidgetview.h"

class GraphicsViewView  : public AbstractWidgetView
{
public:
    GraphicsViewView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // GRAPHICSVIEWVIEW_H
