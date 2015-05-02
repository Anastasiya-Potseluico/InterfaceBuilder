#include "pushbuttonview.h"

PushButtonView::PushButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void PushButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    _itemText.setPos(rect.x()+rect.width()/8, rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Кнопка");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}
