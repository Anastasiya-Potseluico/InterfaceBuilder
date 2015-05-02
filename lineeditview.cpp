#include "lineeditview.h"


LineEditView::LineEditView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void LineEditView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());

    _itemText.setPos(rect.x()+ 0.9*rect.height(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Строка ввода");
    _itemText.setFont(QFont("Cambria", 10));
    _itemText.setParentItem(this);
}
