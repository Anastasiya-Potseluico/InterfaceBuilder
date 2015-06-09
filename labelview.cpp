#include "labelview.h"

/*
* Конструктор представления лейбла.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
LabelView::LabelView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

/*
* Переопределение метода отрисовки представления лейбла.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void LabelView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    // Добавляем текст для лейбла.
    _itemText.setPos(rect.x()+ 0.1*rect.height(), rect.y()+rect.height()*0.03);
    _itemText.setPlainText("Метка");
    _itemText.setFont(QFont("Cambria", 10));
    _itemText.setParentItem(this);
}
