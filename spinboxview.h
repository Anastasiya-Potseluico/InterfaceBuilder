#ifndef SPINBOXVIEW_H
#define SPINBOXVIEW_H

#include "abstractwidgetview.h"

class SpinBoxView : public AbstractWidgetView
{
public:
    SpinBoxView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // SPINBOXVIEW_H
