#include "radiobutton.h"

RadioButton::RadioButton(QPoint&position, int numberOfWidget):AbstractButton(position)
{
    _size = QSize(130,40);
    _text = QString("RadioButton_").append(QString::number(numberOfWidget));
}

QString RadioButton::writeSelfIntoFile(QFile &file)
{
    int g = 0;
}

void RadioButton::drawSelf()
{
    int g = 0;
}
