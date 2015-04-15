#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QImage>
#include "abstractwidget.h"

class AbstractButton : public AbstractWidget
{
public:
    AbstractButton(QPoint &position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
protected:
    bool _checkable;
    bool _isChecked;
    QString _text;
    QImage _icon;


};

#endif // ABSTRACTBUTTON_H
