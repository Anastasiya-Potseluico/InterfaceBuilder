#include "graphicsviewview.h"

/*
* ����������� ������������� ����������.
* param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
*/
GraphicsViewView::GraphicsViewView(AbstractWidget *drawedWidget) : AbstractWidgetView((AbstractWidget*)drawedWidget)
{
}

/*
* ��������������� ������ ��������� ������������� ����������.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void GraphicsViewView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // ������ ������� ������������� �������.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    // ������ ���������� ����� �������������� �������.
    painter->drawLine(rect.x(), rect.y(),rect.x() + rect.width(), rect.y() + rect.height());
    painter->drawLine(rect.x() + rect.width(), rect.y(),rect.x(), rect.y() + rect.height());
}

