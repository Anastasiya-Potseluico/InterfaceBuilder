#include "widgetview.h"
#include "pushbutton.h"
#include "radiobutton.h"
#include <QPainter>

WidgetView::WidgetView(AbstractWidget *drawedWidget)
{
    _drawedWidget = drawedWidget;
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges | ItemIsFocusable);
    //this->setPos(_drawedWidget->getPosition());
}

void WidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(dynamic_cast<RadioButton*>(_drawedWidget))
    {
        drawRadioButton(painter);
    }
    else if(dynamic_cast<PushButton*>(_drawedWidget))
    {
        drawPushButton(painter);
    }
}

QRectF WidgetView::boundingRect() const
{
    QSizeF size = _drawedWidget->getSize();
    QPointF point = _drawedWidget->getPosition();
    QPointF newPos(point.x() - size.height()/2, point.y() - size.height()/2);
    return QRectF(newPos, size);
}

void WidgetView::drawRadioButton(QPainter *painter)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //Рисуем внешний круг виджета
    painter->setPen(pen);
    painter->drawEllipse(rect.x(), rect.y(),rect.height(), rect.height());
    //Рисуем внутренний круг виджета
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.height()/4;
    int newY = rect.y() + rect.height()/4;
    QRectF innerRect = QRectF(newX, newY, rect.height()/2,rect.height()/2);
    painter->drawEllipse(innerRect);
}

void WidgetView::drawPushButton(QPainter *painter)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    //Рисуем внутренний прямоугольник виджета
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.width()/1.3;
    int newY = rect.y() + rect.height()/2;
    QRectF innerRect = QRectF(newX, newY, rect.width()/5,rect.height()/3);
    painter->drawRect(innerRect);
}

void WidgetView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsItem::mousePressEvent(event);
}

void WidgetView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{

   QGraphicsItem::mouseReleaseEvent(event);
}
