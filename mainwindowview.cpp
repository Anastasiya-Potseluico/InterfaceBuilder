#include "mainwindowview.h"

/*
* Конструктор представления главного окна.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
MainWindowView::MainWindowView(AbstractWidget *drawedWidget):AbstractWidgetView(drawedWidget)
{
    this->setFlag(QGraphicsItem::ItemIsMovable,false);
}

/*
* Переопределение метода отрисовки представления главного окна.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void MainWindowView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
}
