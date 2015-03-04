#include "abstractbutton.h"

AbstractButton::AbstractButton(QPoint&position) : AbstractWidget(position)
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
