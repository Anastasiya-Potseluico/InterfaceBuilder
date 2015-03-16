#ifndef WIDGETVIEW_H
#define WIDGETVIEW_H

#include "abstractwidget.h"
#include <QGraphicsItem>

class WidgetView : public QGraphicsItem
{
public:
    WidgetView(AbstractWidget *drawedWidget);
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    AbstractWidget *_drawedWidget;
    void drawRadioButton(QPainter *painter);
    void drawPushButton(QPainter *painter);

};

#endif // WIDGETVIEW_H
