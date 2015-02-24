#include "abstractwidget.h"

QString AbstractWidget::writeSelfIntoFile(QFile &file)
{
    QString result;

    if(!_enabled)
    {
        result.append("<property name=\"enabled\">\n\t<bool>true</bool>\n</property>\n");
    }
   // file.write(result.toLocal8Bit());

}
