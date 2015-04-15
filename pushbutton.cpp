#include "pushbutton.h"

PushButton::PushButton(QPoint &position, int numberOfWidget) : AbstractButton(position,*(new QSize(75,23)))
{
    _defaultOn = true;
    _flat = true;
    _checkable = false;
    _name = QString("PushButton_").append(QString::number(numberOfWidget));
}

QString PushButton::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{

}

void PushButton::drawSelf(QGraphicsScene &scene)
{
    PushButtonView * view = new PushButtonView(this);
    scene.addItem(view);
}
