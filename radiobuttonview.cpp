#include "radiobuttonview.h"

RadioButtonView::RadioButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void RadioButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);

    //������ ������� ���� �������

    painter->setPen(pen);
    painter->drawEllipse(rect.x(), rect.y(),rect.height(), rect.height());
    //������ ���������� ���� �������
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.height()/4;
    int newY = rect.y() + rect.height()/4;
    QRectF innerRect = QRectF(newX, newY, rect.height()/2,rect.height()/2);
    painter->drawEllipse(innerRect);
    _itemText.setPos(rect.x()+ 1.1*rect.height(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("�������������");
    _itemText.setFont(QFont("Cambria", 8));
    _itemText.setParentItem(this);
}
