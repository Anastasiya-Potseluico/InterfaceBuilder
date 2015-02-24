#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include "abstractbutton.h"

class PushButton : public AbstractButton
{
public:
    PushButton();
    QString writeSelfIntoFile(QFile&file);
private:
    bool _defaultOn;
    bool _flat;

};

#endif // PUSHBUTTON_H
