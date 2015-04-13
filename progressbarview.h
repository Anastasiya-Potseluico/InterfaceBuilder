#ifndef PROGRESSBARVIEW_H
#define PROGRESSBARVIEW_H

#include "abstractwidgetview.h"

class ProgressBarView : public AbstractWidgetView
{
public:
    ProgressBarView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // PROGRESSBARVIEW_H
