#include "abstractwidget.h"

AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

QPoint AbstractWidget::getPosition()
{
    QPoint returnedPoint(_position.x(),_position.y());
    return returnedPoint;
}

QSize AbstractWidget::getSize()
{
    QSize returnedSize(_size.width(), _size.height());
    return returnedSize;
}

void AbstractWidget::setPosition(QPoint &position)
{
    _position = position;
}
