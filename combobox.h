#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "abstractbutton.h"

class ComboBox : public AbstractWidget //???????
{
public:
    ComboBox(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf();
};

#endif // COMBOBOX_H
