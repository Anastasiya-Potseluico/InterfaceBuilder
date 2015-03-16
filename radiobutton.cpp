#include "radiobutton.h"



RadioButton::RadioButton(QPoint&position, int numberOfWidget):AbstractButton(position, *(new QSize(82,17)))
{
    _name = QString("RadioButton_").append(QString::number(numberOfWidget));
}

QString RadioButton::writeSelfIntoFile(QFile &file)
{
    int g = 0;
}

void RadioButton::drawSelf(QGraphicsScene &scene)
{
    WidgetView * view = new WidgetView(this);
    scene.addItem(view);
}


