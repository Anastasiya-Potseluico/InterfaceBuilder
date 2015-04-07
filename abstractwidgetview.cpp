#include "abstractwidgetview.h"
#include <QPainter>

AbstractWidgetView::AbstractWidgetView(AbstractWidget *drawedWidget)
{
    _drawedWidget = drawedWidget;
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges | ItemIsFocusable);
    this->setPos(_drawedWidget->getPosition());
}

void AbstractWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}

QRectF AbstractWidgetView::boundingRect() const
{
    QSizeF size = _drawedWidget->getSize();
    QPointF p(0.0,0.0);
    return QRectF(p, size);
}

void AbstractWidgetView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsItem::mousePressEvent(event);
}

void AbstractWidgetView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  
    QPoint p = this->pos().toPoint();
    _drawedWidget->setPosition(p);
    QGraphicsItem::mouseReleaseEvent( event );
}

void AbstractWidgetView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent( event );
    if (x() < 0)
    {
        setPos(0, y());
    }
    else if (x() > 1200 - this->_drawedWidget->getSize().width())
    {
        setPos(1200 - this->_drawedWidget->getSize().width(), y());
    }

    if (y() < 0)
    {
        setPos(x(), 0);
    }
    else if (y() > 1200 - this->_drawedWidget->getSize().height())
    {
        setPos(x(), 1200 - this->_drawedWidget->getSize().height());
    }
}
