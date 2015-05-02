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

QList<QWidget *> AbstractWidget::getSettings()
{
    return _settings;
}

QString AbstractWidget::getName()
{
    return QString(_name);
}

void AbstractWidget::setSize(QSize &size)
{
    _size = size;
}

void AbstractWidget::setPosition(QPoint &position)
{
    _position = position;
}

void AbstractWidget::addWidgetsForSettings()
{
    QCheckBox *enabled = new QCheckBox();
    enabled->setText("Widget is enabled");
    enabled->setChecked(_enabled);
    enabled->setObjectName("enabled");
    _settings.append(enabled);
}

