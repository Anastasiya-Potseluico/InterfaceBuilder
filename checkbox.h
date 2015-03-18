#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "abstractbutton.h"

class CheckBox : public AbstractButton
{
public:
    CheckBox(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _tristate;

};

#endif // CHECKBOX_H
