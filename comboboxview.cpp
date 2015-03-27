#include "comboboxview.h"

ComboBoxView::ComboBoxView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void ComboBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //������ ������� ������������� �������
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());

    //������ ����� "������"
    painter->drawText(QPointF(rect.x()+ 0.5*rect.height(), rect.y()+rect.height()*0.7),"������");

    //������ ���������� ����������� �������
    QPainterPath path;
    path.moveTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.75);
    path.lineTo(rect.x() + 0.75*rect.width(), rect.y() + rect.height()/4);
    path.lineTo(rect.x() + 0.95*rect.width(), rect.y() + rect.height()/4);
    path.lineTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.75);
    painter->setPen(Qt::NoPen);
    painter->fillPath(path,QBrush(Qt::black));




}
