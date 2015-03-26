#include "checkboxview.h"

CheckBoxView::CheckBoxView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{
}

void CheckBoxView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.height(), rect.height());
    //Рисуем внутренний прямоугольник виджета
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.height()/4;
    int newY = rect.y() + rect.height()/4;
    QRectF innerRect = QRectF(newX, newY, rect.height()/2,rect.height()/2);
    painter->drawRect(innerRect);
    //Добавляем текст кнопка-флажок
    QFont font = painter->font();
    font.setPointSize(6);
    painter->setFont(font);

    painter->drawText(QPointF(rect.x()+ 1.1*rect.height(), rect.y()+rect.height()*0.7),"Кнопка-флаг");
}
