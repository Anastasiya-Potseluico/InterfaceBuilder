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

void Calendar::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCalendarWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","gridVisible");
    xmlWriter.writeTextElement("bool",_gridVisible ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","selectedDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_selectedDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_selectedDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_selectedDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimumDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_minimumDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_minimumDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_minimumDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximumDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_maximumDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_maximumDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_maximumDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

    QString dayOfWeek = "Qt::";

    switch (_firstWeekDay)
    {
        case monday :
        {
            dayOfWeek.append("Monday");
            break;
        }
        case tuesday :
        {
            dayOfWeek.append("Tuesday");
            break;
        }
        case wednesday:
        {
            dayOfWeek.append("Wednesday");
            break;
        }
        case thursday :
        {
            dayOfWeek.append("Thursday");
            break;
        }
        case friday :
        {
            dayOfWeek.append("Friday");
            break;
        }
        case saturday :
        {
            dayOfWeek.append("Saturday");
            break;
        }
        case sunday :
        {
            dayOfWeek.append("Sunday");
            break;
        }
    }

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","firstDayOfWeek");
    xmlWriter.writeTextElement("enum", dayOfWeek);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void Calendar::drawSelf(QGraphicsScene &scene)
{
    CalendarView * view = new CalendarView(this);
    scene.addItem(view);
}
