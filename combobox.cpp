#include "combobox.h"
#include "abstractbutton.h"

ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractWidget(position,*(new QSize(69,22)))
{
    _name = QString("ComboBox_").append(QString::number(numberOfWidget));
}

QString ComboBox::writeSelfIntoFile(QFile &file)
{
}

void ComboBox::drawSelf()
{
}
