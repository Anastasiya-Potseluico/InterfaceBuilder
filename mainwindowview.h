#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include "abstractwidgetview.h"

class MainWindowView : public AbstractWidgetView
{
public:
    MainWindowView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // MAINWINDOWVIEW_H
