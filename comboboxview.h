#ifndef COMBOBOXVIEW_H
#define COMBOBOXVIEW_H

#include "abstractwidgetview.h"

class ComboBoxView : public AbstractWidgetView
{
public:
    ComboBoxView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // COMBOBOXVIEW_H
