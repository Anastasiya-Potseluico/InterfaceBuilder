#include "spinboxview.h"


SpinBoxView::SpinBoxView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

void SpinBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    _itemText.setPos(rect.x()+ 0.05*rect.width(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Счетчик");
    _itemText.setFont(QFont("Cambria", 8));
    _itemText.setParentItem(this);
    QPainterPath path;
    path.moveTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.8);
    path.lineTo(rect.x() + 0.75*rect.width(), rect.y() + rect.height()*0.6);
    path.lineTo(rect.x() + 0.95*rect.width(), rect.y() + rect.height()*0.6);
    path.lineTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.8);
    painter->setPen(Qt::NoPen);
    painter->fillPath(path,QBrush(Qt::black));
    path.moveTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.2);
    path.lineTo(rect.x() + 0.75*rect.width(), rect.y() + rect.height()*0.4);
    path.lineTo(rect.x() + 0.95*rect.width(), rect.y() + rect.height()*0.4);
    path.lineTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.2);
    painter->fillPath(path,QBrush(Qt::black));
}
