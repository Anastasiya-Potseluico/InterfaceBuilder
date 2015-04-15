#include "listwidgetview.h"

ListWidgetView::ListWidgetView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

void ListWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);
    painter->drawText(QPointF(rect.x()+ 0.35*rect.width(), rect.y()+rect.height()*0.3),"Список");
    painter->drawText(QPointF(rect.x()+ 0.35*rect.width(), rect.y()+rect.height()*0.45),"некоторых");
    painter->drawText(QPointF(rect.x()+ 0.35*rect.width(), rect.y()+rect.height()*0.6),"данных");
}
