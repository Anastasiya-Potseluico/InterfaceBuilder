#include "checkbox.h"

CheckBox::CheckBox(QPoint &position, int numberOfWidget):AbstractButton(position,*(new QSize(70,17)))
{
    _tristate = false;
    _name = QString("CheckBox_").append(QString::number(numberOfWidget));
}

QString CheckBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
}

void CheckBox::drawSelf(QGraphicsScene &scene)
{
    CheckBoxView * view = new CheckBoxView(this);
    scene.addItem(view);
}
