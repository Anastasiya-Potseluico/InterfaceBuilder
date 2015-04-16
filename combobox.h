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
    QList<QString> _items; // ������ ����������.
    bool _isEditable; // ���� ����������� ��������������.
    int _currentIndex; // ������� ������ ������ ����������.

};

#endif // COMBOBOX_H
