#ifndef LINEEDIT_H
#define LINEEDIT_H
#include "abstractwidget.h"
#include "lineeditview.h"

class LineEdit : public AbstractWidget
{
public:
    LineEdit(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    QString _text; // ���������� ���������.
    bool _readOnly; // ���� ������ �� ������ �������.
};

#endif // LINEEDIT_H
