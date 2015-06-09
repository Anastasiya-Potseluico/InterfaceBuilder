#include "comboboxview.h"

/*
* Конструктор представления комбобокса.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
ComboBoxView::ComboBoxView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

/*
* Переопределение метода отрисовки представления комбобокса.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void ComboBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);
    // Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());
    // Добавляем текст для виджета.
    _itemText.setPos(rect.x()+ 0.05*rect.width(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Список");
    _itemText.setFont(QFont("Cambria", 10));
    _itemText.setParentItem(this);
    // Рисуем внутренний треугольник виджета.
    QPainterPath path;
    path.moveTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.75);
    path.lineTo(rect.x() + 0.75*rect.width(), rect.y() + rect.height()/4);
    path.lineTo(rect.x() + 0.95*rect.width(), rect.y() + rect.height()/4);
    path.lineTo(rect.x() + 0.85*rect.width(), rect.y() + rect.height()*0.75);
    painter->setPen(Qt::NoPen);
    painter->fillPath(path,QBrush(Qt::black));
}
