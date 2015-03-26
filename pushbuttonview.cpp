#include "pushbuttonview.h"

PushButtonView::PushButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void PushButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);
    //������ ������� ������������� �������
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    //������ ���������� ������������� �������
    painter->setBrush(QBrush(Qt::black));
    painter->drawText(QPointF(rect.x()+rect.width()/4, rect.y()+rect.height()/1.5),"������");
}
