#include "checkboxview.h"

/*
* Конструктор представления чекбокса.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
CheckBoxView::CheckBoxView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

/*
* Переопределение метода отрисовки представления чекбокса.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void CheckBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = widgetSize();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета.
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.height(), rect.height());
    //Рисуем внутренний прямоугольник виджета.
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.height()/4;
    int newY = rect.y() + rect.height()/4;
    QRectF innerRect = QRectF(newX, newY, rect.height()/2,rect.height()/2);
    painter->drawRect(innerRect);
    // Добавляем текст на виджет.
    _itemText.setPos(rect.x()+ 1.1*rect.height(), rect.y()+rect.height()*0.05);
    _itemText.setPlainText("Кнопка-флаг");
    _itemText.setFont(QFont("Cambria", 8));
    _itemText.setParentItem(this);
}
