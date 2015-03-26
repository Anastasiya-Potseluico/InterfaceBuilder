#ifndef CHECKBOXVIEW_H
#define CHECKBOXVIEW_H

#include "abstractwidgetview.h"

class CheckBoxView : public AbstractWidgetView
{
public:
    CheckBoxView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CHECKBOXVIEW_H
