#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "abstractbutton.h"
#include "checkboxview.h"

class CheckBox : public AbstractButton
{
public:
    CheckBox(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _tristate;

};

#endif // CHECKBOX_H
