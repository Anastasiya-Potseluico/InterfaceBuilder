#include "combobox.h"

ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractButton(position)
{
    _size = QSize(130,40);
    _text = QString("RadioButton_").append(QString::number(numberOfWidget));
}

QString ComboBox::writeSelfIntoFile(QFile &file)
{
}

void ComboBox::drawSelf()
{
}
