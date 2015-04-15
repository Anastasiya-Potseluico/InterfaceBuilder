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
    QDate _selectedDate; // Выбранная дата.
    QDate _minimumDate; // Минимальная дата.
    QDate _maximumDate; // Максимальная дата.
    weekDays _firstWeekDay; // Первый день недели для отображения.
    bool _gridVisible; // Видимость сетки календаря.
};

#endif // CALENDAR_H
