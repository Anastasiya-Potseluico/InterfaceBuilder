#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QImage>
#include "abstractwidget.h"

class AbstractButton : public AbstractWidget
{
public:
    AbstractButton(QPoint &position);
    virtual void drawSelf() = 0;

protected:
    bool _checkable;
    bool _isChecked;
    bool _down;
    QString _text;
    QImage _icon;
    QString writeSelfIntoFile(QFile&file);
};

#endif // ABSTRACTBUTTON_H
