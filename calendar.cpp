#include "calendar.h"


Calendar::Calendar(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(216,155)))
{
    _name = QString("Calendar_").append(QString::number(numberOfWidget));
    _gridVisible = false;
    _selectedDate = QDate::currentDate();
    _maximumDate = QDate(2099,12,31);
    _minimumDate = QDate(1900,12,12);
    _firstWeekDay = sunday;
}

QString Calendar::writeSelfIntoFile(QFile &file)
{
}

void Calendar::drawSelf(QGraphicsScene &scene)
{
    CalendarView * view = new CalendarView(this);
    scene.addItem(view);
}
