#include "mainwindowview.h"

/*
* ����������� ������������� �������� ����.
* param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
*/
MainWindowView::MainWindowView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
    this->setFlag(QGraphicsItem::ItemIsMovable,false);
}

/*
* ��������������� ������ ��������� ������������� �������� ����.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void MainWindowView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // ������ ������� ������������� �������.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
}
