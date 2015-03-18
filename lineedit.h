#ifndef LINEEDIT_H
#define LINEEDIT_H
#include "abstractwidget.h"

class LineEdit : public AbstractWidget
{
public:
    LineEdit(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    QString _text; // Содержание лайнэдита.
    bool _readOnly; // Флаг только на чтение виджета.
};

#endif // LINEEDIT_H
