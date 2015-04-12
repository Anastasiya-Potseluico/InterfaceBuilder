#include "progressbar.h"

ProgressBar::ProgressBar(QPoint &position, int numberOfWidget) :AbstractWidget(position,*(new QSize(118,23)))
{
    _name = QString("ProgressBar_").append(QString::number(numberOfWidget));
    _textVisible = true;
    _value = 20;
    _invertedAppearance = false;
    _minValue = 0;
    _maxValue = 100;
}

QString ProgressBar::writeSelfIntoFile(QFile &file)
{
}

void ProgressBar::drawSelf(QGraphicsScene &scene)
{
}
