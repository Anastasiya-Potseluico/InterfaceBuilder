#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include "abstractwidgetview.h"

class CalendarView : public AbstractWidgetView
{
public:
    CalendarView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CALENDARVIEW_H
