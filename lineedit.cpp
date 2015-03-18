#include "lineedit.h"


LineEdit::LineEdit(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(130,40)))
{
    _name = QString("LineEdit_").append(QString::number(numberOfWidget));
    _text = QString("");
    _readOnly = false;
}

QString LineEdit::writeSelfIntoFile(QFile &file)
{
}

void LineEdit::drawSelf(QGraphicsScene &scene)
{
}
