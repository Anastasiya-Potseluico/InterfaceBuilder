#include "radiobutton.h"

RadioButton::RadioButton(QPoint&position):AbstractButton(position)
{
    _size = QSize(4,5);
}

QString RadioButton::writeSelfIntoFile(QFile &file)
{
    int g = 0;
}

void RadioButton::drawSelf()
{
    int g = 0;
}
