#include "tablewidgetview.h"

TableWidgetView::TableWidgetView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
}

void TableWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    //������ ������� ������������� �������
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->drawLine(QPointF(rect.x()+0.1*rect.width(),rect.y()), QPointF(rect.x()+0.1*rect.width(),rect.y()+rect.height()));
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()*0.1), QPointF(rect.x()+rect.width(),rect.y()+rect.height()*0.1));
    _itemText.setPos(rect.x()+ 0.2*rect.width(), rect.y()+rect.height()*0.3);
    _itemText.setPlainText("������� \n��������� \n������");
    _itemText.setFont(QFont("Cambria", 12));
    _itemText.setParentItem(this);
}
