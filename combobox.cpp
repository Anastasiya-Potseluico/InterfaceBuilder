#include "combobox.h"
#include "abstractbutton.h"

ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractWidget(position,*(new QSize(69,22)))
{
    _name = QString("ComboBox_").append(QString::number(numberOfWidget));
    _currentIndex = -1;
    _isEditable = false;
}

QString ComboBox::writeSelfIntoFile(QFile &file)
{

}

void ComboBox::drawSelf(QGraphicsScene &scene)
{
    ComboBoxView * view = new ComboBoxView(this);
    scene.addItem(view);
}
