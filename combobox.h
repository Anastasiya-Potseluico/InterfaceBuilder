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
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    QStringList _items; // ������ ����������.
    bool _isEditable; // ���� ����������� ��������������.
    int _currentIndex; // ������� ������ ������ ����������.

};

#endif // COMBOBOX_H
