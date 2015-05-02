#include "mainwindowview.h"

MainWindowView::MainWindowView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
    this->setFlag(QGraphicsItem::ItemIsMovable,false);
}

void MainWindowView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
}
