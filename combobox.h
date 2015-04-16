#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "abstractwidget.h"
#include "comboboxview.h"

class ComboBox : public AbstractWidget
{
public:
    ComboBox(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    QList<QString> _items; // Айтемы комбобокса.
    bool _isEditable; // Флаг возможности редактирования.
    int _currentIndex; // Текущий индекс айтема комбобокса.

};

#endif // COMBOBOX_H
