#include "radiobutton.h"

RadioButton::RadioButton(QPoint&position, int numberOfWidget):AbstractButton(position, *(new QSize(82,17)))
{
    QString name = QString("RadioButton_").append(QString::number(numberOfWidget));
}

QString RadioButton::writeSelfIntoFile(QFile &file)
{
    int g = 0;
}

void RadioButton::drawSelf()
{
    int g = 0;
}
