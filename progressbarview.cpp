#include "progressbarview.h"

ProgressBarView::ProgressBarView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void ProgressBarView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->setBrush(QBrush(Qt::green));
    painter->drawRect(rect.x(), rect.y(), rect.x()+0.2*rect.width(), rect.height());
    painter->setPen(pen);
    _itemText.setPos(rect.x()+ 0.35*rect.width(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("20%");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}
