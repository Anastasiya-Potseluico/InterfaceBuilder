#include "progressbarview.h"

ProgressBarView::ProgressBarView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void ProgressBarView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->setBrush(QBrush(Qt::green));
    painter->drawRect(rect.x(), rect.y(), rect.x()+0.2*rect.width(), rect.height());
    painter->setPen(pen);
    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);
    painter->drawText(QPointF(rect.x()+ 0.35*rect.width(), rect.y()+rect.height()*0.8),"20%");
}
