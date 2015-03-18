#include "radiobuttonview.h"

RadioButtonView::RadioButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void RadioButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
