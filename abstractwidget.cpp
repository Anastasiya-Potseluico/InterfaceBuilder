#include "abstractwidget.h"

AbstractWidget::AbstractWidget(QPoint &position)
{
    this->_position = position;
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
