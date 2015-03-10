#include "abstractbutton.h"

AbstractButton::AbstractButton(QPoint&position,QSize &size) : AbstractWidget(position, size)
{
    //AbstractWidget(position);
    _checkable = true;
    _isChecked = false;
    _down = false;
}

QString AbstractButton::writeSelfIntoFile(QFile &file)
{
   QString res = AbstractWidget::writeSelfIntoFile(file);
}
