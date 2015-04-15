#ifndef RADIOBUTTON_H
#define RADIOBUTTON_H

#include "abstractbutton.h"
#include "radiobuttonview.h"

class RadioButton : public AbstractButton
{
public:
    RadioButton(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

};

#endif // RADIOBUTTON_H
