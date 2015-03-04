#include "abstractbutton.h"

AbstractButton::AbstractButton(QPoint&position) : AbstractWidget(position)
{
    //AbstractWidget(position);
}

QString AbstractButton::writeSelfIntoFile(QFile &file)
{
   QString res = AbstractWidget::writeSelfIntoFile(file);
}
