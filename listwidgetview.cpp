#include "listwidgetview.h"

/*
* Конструктор представления списка.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
ListWidgetView::ListWidgetView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

/*
* Переопределение метода отрисовки представления списка.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void ListWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    // Добавляем текст на список.
    _itemText.setPos(rect.x()+ 0.2*rect.width(), rect.y()+rect.height()*0.2);
    _itemText.setPlainText("Список \nнекоторых \nданных");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}
