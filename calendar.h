#ifndef CALENDAR_H
#define CALENDAR_H

#include <QDate>
#include "abstractwidget.h"
#include "calendarview.h"

enum weekDays {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

class Calendar : public AbstractWidget
{
public:
    Calendar(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    QDate _selectedDate; // ��������� ����.
    QDate _minimumDate; // ����������� ����.
    QDate _maximumDate; // ������������ ����.
    weekDays _firstWeekDay; // ������ ���� ������ ��� �����������.
    bool _gridVisible; // ��������� ����� ���������.
};

#endif // CALENDAR_H
