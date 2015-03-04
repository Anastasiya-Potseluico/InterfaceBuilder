#include "pushbutton.h"

PushButton::PushButton(QPoint &position) : AbstractButton(position)
{
    _defaultOn = true;
    _flat = true;
    _checkable = false;
}

QString PushButton::writeSelfIntoFile(QFile &file)
{
    QString result;
   // result = (AbstractButton::writeSelfIntoFile(file));
  //  file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(_defaultOn)
    {
        result.append("<property name=\"default\">\n\t<bool>true</bool>\n</property>\n");
    }
    if(_flat)
    {
        result.append("<property name=\"flat\">\n\t<bool>true</bool>\n</property>\n");
    }
   // bool ok = file.write(result.toStdString().c_str());
    int h = 0;
}
