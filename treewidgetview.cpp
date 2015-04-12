#include "treewidgetview.h"

TreeWidgetView::TreeWidgetView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
}

void TreeWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    painter->drawLine(QPointF(rect.x(),rect.y()+rect.height()/4), QPointF(rect.x()+rect.width(),rect.y()+rect.height()/4));
    QFont font = painter->font();
    font.setPointSize(12);
    painter->setFont(font);
    painter->drawText(QPointF(rect.x()+ 0.4*rect.width(), rect.y()+rect.height()*0.45),"Дерево");
    painter->drawText(QPointF(rect.x()+ 0.4*rect.width(), rect.y()+rect.height()*0.6),"некоторых");
    painter->drawText(QPointF(rect.x()+ 0.4*rect.width(), rect.y()+rect.height()*0.75),"данных");
}
