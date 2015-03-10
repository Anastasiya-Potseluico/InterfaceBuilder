#include "lineedit.h"


LineEdit::LineEdit(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(130,40)))
{
    _name = QString("LineEdit_").append(QString::number(numberOfWidget));
}

QString LineEdit::writeSelfIntoFile(QFile &file)
{
}

void LineEdit::drawSelf()
{
}
