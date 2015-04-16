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
    QString _text; // Содержание лайнэдита.
    bool _readOnly; // Флаг только на чтение виджета.
};

#endif // LINEEDIT_H
