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
    QString _text; // ���������� ���������.
    bool _readOnly; // ���� ������ �� ������ �������.
};

#endif // LINEEDIT_H
