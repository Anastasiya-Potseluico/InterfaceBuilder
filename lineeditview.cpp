#include "lineeditview.h"


LineEditView::LineEditView(AbstractWidget *drawedWidget) : AbstractWidgetView(drawedWidget)
{
}

void LineEditView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    QPen pen(Qt::black, 1);

    //Рисуем внешний прямоугольник виджета
    painter->setPen(pen);
    painter->drawRect(rect.x(), rect.y(),rect.width(), rect.height());

    //Добавляем текст "строка ввода"
    QFont font = painter->font();
    font.setPointSize(10);
    painter->setFont(font);

    painter->drawText(QPointF(rect.x()+ 0.9*rect.height(), rect.y()+rect.height()*0.7),"Строка ввода");
}
