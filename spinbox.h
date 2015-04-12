#ifndef SPINBOX_H
#define SPINBOX_H

#include "abstractwidget.h"
#include "spinboxview.h"

class SpinBox : public AbstractWidget
{
public:
    SpinBox(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _readOnly;
    int _maxValue;
    int _minValue;
    int _singleStep;
    int _value;
};

#endif // SPINBOX_H
