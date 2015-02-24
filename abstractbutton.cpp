#include "abstractbutton.h"

AbstractButton::AbstractButton()
{
}

QString AbstractButton::writeSelfIntoFile(QFile &file)
{
   QString res = AbstractWidget::writeSelfIntoFile(file);
}
