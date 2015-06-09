#include "lineeditview.h"

/*
* Конструктор представления строки ввода.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
LineEditView::LineEditView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

/*
* Переопределение метода отрисовки представления строки ввода.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void LineEditView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    // Добавляем надпись на виджет.
    _itemText.setPos(rect.x()+ 0.9*rect.height(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Строка ввода");
    _itemText.setFont(QFont("Cambria", 10));
    _itemText.setParentItem(this);
}
