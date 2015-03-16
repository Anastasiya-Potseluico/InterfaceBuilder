#include "abstractwidget.h"

AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

QString AbstractWidget::writeSelfIntoFile(QFile &file)
{
    QString result;
    result.append("<property name=\"geometry\">\n<rect>\n<x>").append(QString::number(_position.x()))
          .append("</x>\n").append("<y>").append(QString::number(_position.y())).append("</y>\n")
          .append("<width>").append(QString::number(_size.width())).append("</width>\n")
          .append("<height>").append(QString::number(_size.height())).append("</height>\n")
          .append("</rect>\n").append("</property>\n");

    if(!_enabled)
    {
        result.append("<property name=\"enabled\">\n\t<bool>true</bool>\n</property>\n");
    }
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
