#include "graphicsvewview.h"

GraphicsVewView::GraphicsVewView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void GraphicsVewView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    //Рисуем внутренние линии перечеркивания виджета
    painter->drawLine(rect.x(), rect.y(),rect.x() + rect.width(), rect.y() + rect.height());
    painter->drawLine(rect.x() + rect.width(), rect.y(),rect.x(), rect.y() + rect.height());
}
