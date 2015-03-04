#ifndef LINEEDIT_H
#define LINEEDIT_H
#include "abstractwidget.h"

class LineEdit : public AbstractWidget
{
public:
    LineEdit(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf();
};

#endif // LINEEDIT_H
