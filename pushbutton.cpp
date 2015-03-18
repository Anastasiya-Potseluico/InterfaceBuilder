#include "pushbutton.h"

PushButton::PushButton(QPoint &position, int numberOfWidget) : AbstractButton(position,*(new QSize(75,23)))
{
    _defaultOn = true;
    _flat = true;
    _checkable = false;
    _name = QString("PushButton_").append(QString::number(numberOfWidget));
}

QString PushButton::writeSelfIntoFile(QFile &file)
{
    QString result;
   // result = (AbstractButton::writeSelfIntoFile(file));
  //  file.open(QIODevice::ReadOnly | QIODevice::Text);
    result.append("<widget class=\"QPushButton\" name=\"").append(_name).append("\">\n");
    AbstractButton::writeSelfIntoFile(file);
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

void PushButton::drawSelf(QGraphicsScene &scene)
{
    PushButtonView * view = new PushButtonView(this);
    scene.addItem(view);
}
