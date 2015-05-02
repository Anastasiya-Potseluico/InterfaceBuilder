#include "labelview.h"

LabelView::LabelView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void LabelView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
     painter->setPen(pen);
    //Добавляем текст "строка ввода"
     _itemText.setPos(rect.x()+ 0.1*rect.height(), rect.y()+rect.height()*0.03);
     _itemText.setPlainText("Метка");
     _itemText.setFont(QFont("Cambria", 10));
     _itemText.setParentItem(this);
}
