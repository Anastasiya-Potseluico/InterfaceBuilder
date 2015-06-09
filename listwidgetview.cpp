#include "listwidgetview.h"

/*
* ����������� ������������� ������.
* param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
*/
ListWidgetView::ListWidgetView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

/*
* ��������������� ������ ��������� ������������� ������.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void ListWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // ������ ������� ������������� �������.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    // ��������� ����� �� ������.
    _itemText.setPos(rect.x()+ 0.2*rect.width(), rect.y()+rect.height()*0.2);
    _itemText.setPlainText("������ \n��������� \n������");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}
