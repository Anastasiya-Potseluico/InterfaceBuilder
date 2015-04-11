#include "calendarview.h"


CalendarView::CalendarView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
}

void CalendarView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()/4), QPointF(rect.x()+rect.width(),rect.y()+rect.height()/4));

    painter->drawLine(QPointF(rect.x()+rect.width()/2,rect.y()+rect.height()/4), QPointF(rect.x()+rect.width()/2,rect.y()+rect.height()));
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()*0.63), QPointF(rect.x()+rect.width(),rect.y()+rect.height()*0.63));
    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);

    painter->drawText(QPointF(rect.x()+ 0.3*rect.width(), rect.y()+rect.height()*0.15),"Календарь");
}

