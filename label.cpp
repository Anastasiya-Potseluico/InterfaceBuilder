#include "label.h"


Label::Label(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(46,13)))
{
    _verticalAlignment = center_v;
    _horizontalAlignment = left;
    _name = QString("Label_").append(QString::number(numberOfWidget));
}

QString Label::writeSelfIntoFile(QFile &file)
{
}

void Label::drawSelf(QGraphicsScene &scene)
{
}
