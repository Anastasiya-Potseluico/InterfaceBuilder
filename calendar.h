#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>
#include <QDateEdit>
#include <QComboBox>
#include "abstractwidget.h"
#include "calendarview.h"

enum weekDays {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

class Calendar : public AbstractWidget
{
public:
    Calendar(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    void addWidgetsForSettings();
    QString getClassname();

private:
    QDate _selectedDate; // ��������� ����.
    QDate _minimumDate; // ����������� ����.
    QDate _maximumDate; // ������������ ����.
    weekDays _firstWeekDay; // ������ ���� ������ ��� �����������.
    bool _gridVisible; // ��������� ����� ���������.
};

#endif // CALENDAR_H
