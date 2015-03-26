#ifndef LABELVIEW_H
#define LABELVIEW_H

#include "abstractwidgetview.h"

class LabelView : public AbstractWidgetView
{
public:
    LabelView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LABELVIEW_H
