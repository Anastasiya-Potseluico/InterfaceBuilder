#ifndef PUSHBUTTONVIEW_H
#define PUSHBUTTONVIEW_H

#include "abstractwidgetview.h"

class PushButtonView : public AbstractWidgetView
{
public:
    PushButtonView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // PUSHBUTTONVIEW_H
