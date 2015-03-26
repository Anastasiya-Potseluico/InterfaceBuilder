#ifndef LINEEDITVIEW_H
#define LINEEDITVIEW_H

#include "abstractwidgetview.h"

class LineEditView : public AbstractWidgetView
{
public:
    LineEditView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LINEEDITVIEW_H
