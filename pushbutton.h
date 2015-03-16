#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "abstractbutton.h"
#include "widgetview.h"
#include <QPoint>

class PushButton : public AbstractButton
{
public:
    PushButton(QPoint&position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);
private:
    bool _defaultOn;
    bool _flat;

};

#endif // PUSHBUTTON_H
