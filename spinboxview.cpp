#include "spinboxview.h"


SpinBoxView::SpinBoxView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

void SpinBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    QFont font = painter->font();
    font.setPointSize(6);
    painter->setFont(font);
    painter->drawText(QPointF(rect.x()+ 0.05*rect.width(), rect.y()+rect.height()*0.7),"Счетчик");
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
