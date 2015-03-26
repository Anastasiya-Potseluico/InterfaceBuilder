#include "labelview.h"

LabelView::LabelView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void LabelView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
     painter->setPen(pen);
    //Добавляем текст "строка ввода"

    painter->drawText(QPointF(rect.x()+ 0.1*rect.height(), rect.y()+rect.height()*0.7),"Метка");
}
