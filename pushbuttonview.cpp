#include "pushbuttonview.h"

PushButtonView::PushButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void PushButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
