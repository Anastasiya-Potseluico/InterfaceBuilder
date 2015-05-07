#include "calendar.h"


Calendar::Calendar(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(216,155)))
{
    _name = QString("Calendar_").append(QString::number(numberOfWidget));
    _gridVisible = false;
    _selectedDate = QDate::currentDate();
    _maximumDate = QDate(2099,12,31);
    _minimumDate = QDate(1900,12,31);
    _firstWeekDay = sunday;
    addWidgetsForSettings();
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

void Calendar::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    QString temp;
    temp = settings.value("maxDate");
    _maximumDate = QDate::fromString(temp);
    temp = settings.value("minDate");
    _minimumDate = QDate::fromString(temp);
    temp = settings.value("selectedDate");
    _selectedDate = QDate::fromString(temp);
    temp = settings.value("gridVisible");
    if(temp == "true")
        _gridVisible = true;
    else
        _gridVisible = false;
    temp = settings.value("weekDays");
    if(temp == "Понедельник")
    {
        _firstWeekDay = monday;
    }
    else if (temp == "Вторник")
    {
        _firstWeekDay = tuesday;
    }
    else if (temp == "Среда")
    {
        _firstWeekDay = wednesday;
    }
    else if (temp == "Четверг")
    {
        _firstWeekDay = thursday;
    }
    else if (temp == "Пятница")
    {
        _firstWeekDay = friday;
    }
    else if (temp == "Суббота")
    {
        _firstWeekDay = saturday;
    }
    else if (temp == "Воскесенье")
    {
        _firstWeekDay = sunday;
    }
    _settings.clear();
    addWidgetsForSettings();
}

void Calendar::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Calendar");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QLabel *labelMax = new QLabel("Maximum Date");
    QDateEdit *maxDate = new QDateEdit();
    maxDate->setObjectName("maxDate");
    maxDate->setDate(_maximumDate);

    QLabel *labelMin = new QLabel("Minimum Date");
    QDateEdit *minDate = new QDateEdit();
    minDate->setObjectName("minDate");
    minDate->setDate(_minimumDate);

    QLabel *labelSel = new QLabel("Selected Date");
    QDateEdit *selectedDate = new QDateEdit();
    selectedDate->setObjectName("selectedDate");
    selectedDate->setDate(_selectedDate);

    QCheckBox *gridVisible = new QCheckBox();
    gridVisible->setText("Grid Visible");
    gridVisible->setChecked(_gridVisible);
    gridVisible->setObjectName("gridVisible");

    QLabel *labelWeek= new QLabel("First Weekday");
    QComboBox *weekDays = new QComboBox();
    weekDays->setObjectName("weekDays");
    weekDays->addItem("Понедельник");
    weekDays->addItem("Вторник");
    weekDays->addItem("Среда");
    weekDays->addItem("Четверг");
    weekDays->addItem("Пятница");
    weekDays->addItem("Суббота");
    weekDays->addItem("Воскресенье");
    switch (_firstWeekDay)
    {
    case monday:
        weekDays->setCurrentIndex(0);
        break;
    case tuesday:
        weekDays->setCurrentIndex(1);
        break;
    case wednesday:
        weekDays->setCurrentIndex(2);
        break;
    case thursday:
        weekDays->setCurrentIndex(3);
        break;
    case friday:
        weekDays->setCurrentIndex(4);
        break;
    case saturday:
        weekDays->setCurrentIndex(5);
        break;
    case sunday:
        weekDays->setCurrentIndex(6);
        break;
    }

    _settings.append(labelMax);
    _settings.append(maxDate);
    _settings.append(labelMin);
    _settings.append(minDate);
    _settings.append(labelSel);
    _settings.append(selectedDate);
    _settings.append(gridVisible);
    _settings.append(labelWeek);
    _settings.append(weekDays);
}

QString Calendar::getClassname()
{
    return QString("Calendar");
}
