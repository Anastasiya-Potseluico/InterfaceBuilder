#ifndef RADIOBUTTONVIEW_H
#define RADIOBUTTONVIEW_H

#include "abstractwidgetview.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

class RadioButtonView : public AbstractWidgetView
{
public:
    RadioButtonView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // RADIOBUTTONVIEW_H
