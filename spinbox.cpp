#include "spinbox.h"

SpinBox::SpinBox(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(42,22)))
{
    _name = QString("SpinBox_").append(QString::number(numberOfWidget));
    _readOnly = false;
    _maxValue = 0;
    _minValue = 99;
    _singleStep = 1;
    _value = 0;
}

QString SpinBox::writeSelfIntoFile(QFile &file)
{
}

void SpinBox::drawSelf(QGraphicsScene &scene)
{
    SpinBoxView * view = new SpinBoxView(this);
    scene.addItem(view);
}
