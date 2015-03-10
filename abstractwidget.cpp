#include "abstractwidget.h"

AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

QString AbstractWidget::writeSelfIntoFile(QFile &file)
{
    QString result;

    if(!_enabled)
    {
        result.append("<property name=\"enabled\">\n\t<bool>true</bool>\n</property>\n");
    }
   // file.write(result.toLocal8Bit());

}
