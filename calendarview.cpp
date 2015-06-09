#include "calendarview.h"

/*
* Конструктор представления календаря.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
CalendarView::CalendarView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
    // Вызываем родительский конструктор.
}

/*
* Переопределение метода отрисовки представления календаря.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void CalendarView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()/4), QPointF(rect.x()+rect.width(),rect.y()+rect.height()/4));
    // Рисуем разделительные линии.
    painter->drawLine(QPointF(rect.x()+rect.width()/2,rect.y()+rect.height()/4), QPointF(rect.x()+rect.width()/2,rect.y()+rect.height()));
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()*0.63), QPointF(rect.x()+rect.width(),rect.y()+rect.height()*0.63));
    // Делаем надпись внутри календаря.
    _itemText.setPos(rect.x()+ 0.3*rect.width(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Календарь");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}

