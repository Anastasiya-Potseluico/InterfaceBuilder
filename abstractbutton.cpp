#include "abstractbutton.h"

AbstractButton::AbstractButton(QPoint&position,QSize &size) : AbstractWidget(position, size)
{
    //AbstractWidget(position);
    _checkable = true;
    _isChecked = false;
    _text = QString("");
}

QString AbstractButton::writeSelfIntoFile(QFile &file)
{
   QString res = AbstractWidget::writeSelfIntoFile(file);

   if(!_checkable)
   {
       res.append("<property name=\"checkable\">\n\t<bool>false</bool>\n</property>\n");
   }
   if(_isChecked)
   {
       res.append("<property name=\"checked\">\n\t<bool>true</bool>\n</property>\n");
   }
   if(_text.size())
   {
       res.append("<property name=\"text\">\n\t<string>").append(_text).append("</string>\n</property>\n");
   }
   if(!_icon.isNull())
   {
   // QICON!!!! TODO
   }
}
