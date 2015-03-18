#ifndef AbstractWidgetView_H
#define AbstractWidgetView_H

#include "abstractwidget.h"
#include <QGraphicsItem>

class AbstractWidgetView : public QGraphicsItem
{
public:
    AbstractWidgetView(AbstractWidget *drawedWidget);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;

protected:
    AbstractWidget *_drawedWidget;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
    void drawRadioButton(QPainter *painter);
    void drawPushButton(QPainter *painter);

};

#endif // AbstractWidgetView_H
