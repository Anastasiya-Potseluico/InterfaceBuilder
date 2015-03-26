#include "radiobuttonview.h"

RadioButtonView::RadioButtonView(AbstractWidget *drawedWidget) :AbstractWidgetView(drawedWidget)
{

}

void RadioButtonView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний круг виджета

    painter->setPen(pen);
    painter->drawEllipse(rect.x(), rect.y(),rect.height(), rect.height());
    //Рисуем внутренний круг виджета
    painter->setBrush(QBrush(Qt::black));
    int newX = rect.x() + rect.height()/4;
    int newY = rect.y() + rect.height()/4;
    QRectF innerRect = QRectF(newX, newY, rect.height()/2,rect.height()/2);
    painter->drawEllipse(innerRect);
    //Добавляем текст Radio Button
    QFont font = painter->font();
    font.setPointSize(6);
    painter->setFont(font);

    painter->drawText(QPointF(rect.x()+ 1.1*rect.height(), rect.y()+rect.height()*0.7),"Переключатель");
}
