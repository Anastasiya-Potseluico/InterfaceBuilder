#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "abstractwidget.h"

class ComboBox : public AbstractWidget
{
public:
    ComboBox(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf();

private:
    QList<QString> _items; // ������ ����������.
    bool _isEditable; // ���� ����������� ��������������.
    int _currentIndex; // ������� ������ ������ ����������.

};

#endif // COMBOBOX_H
