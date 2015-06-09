#include "calendar.h"

/*
* Конструктор календаря.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
Calendar::Calendar(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(216,155)))
{
    _name = QString("Calendar_").append(QString::number(numberOfWidget));
    _gridVisible = false;
    _selectedDate = QDate::currentDate();
    _maximumDate = QDate(2099,12,31);
    _minimumDate = QDate(1900,12,31);
    _firstWeekDay = sunday;
    // Сразу же добавить нужные виджеты для диалогового окна настроек.
    addWidgetsForSettings();
}

/*
* Метод записи календаря в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void Calendar::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя виджета.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCalendarWidget");
    xmlWriter.writeAttribute("name",_name);
    // Записать свойства, общие для всех виджетов.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать видимость сетки календаря.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","gridVisible");
    xmlWriter.writeTextElement("bool",_gridVisible ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать выбранную дату.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","selectedDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_selectedDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_selectedDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_selectedDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
    // Записать минимальную дату.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimumDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_minimumDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_minimumDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_minimumDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
    // Записать максимальную дату.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximumDate");

    xmlWriter.writeStartElement("date");
    xmlWriter.writeTextElement("year",QString::number(_maximumDate.year()));
    xmlWriter.writeTextElement("month",QString::number(_maximumDate.month()));
    xmlWriter.writeTextElement("day",QString::number(_maximumDate.day()));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
    // Записать первый день недели для отображения.
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

/*
* Метод отрисовки календаря.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void Calendar::drawSelf(QGraphicsScene &scene)
{
    // Создать представление календаря.
    CalendarView * view = new CalendarView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для календаря.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void Calendar::setSettings(QMap<QString, QString> &settings)
{
    // Установить настройки, общие для всех виджетов.
    AbstractWidget::setSettings(settings);
    QString temp;
    // Установить максимальную дату.
    temp = settings.value("maxDate");
    _maximumDate = QDate::fromString(temp);
    // Установить минимальную дату.
    temp = settings.value("minDate");
    _minimumDate = QDate::fromString(temp);
    // Установить текущую дату.
    temp = settings.value("selectedDate");
    _selectedDate = QDate::fromString(temp);
    // Установить видимость сетки.
    temp = settings.value("gridVisible");
    if(temp == "true")
        _gridVisible = true;
    else
        _gridVisible = false;
    // Установить первый день недели.
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
    // Перезаписать виджеты настроек.
    addWidgetsForSettings();
}

/*
* Метод для добавления нужных виджетов настроек для календаря в диалоговом окне.
*/
void Calendar::addWidgetsForSettings()
{
    // Добавить строку для изменения имени виджета.
    QLabel *labelName = new QLabel("Name Of Calendar");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить общие виджеты для настройки.
    AbstractWidget::addWidgetsForSettings();
    // Добавить виджет для редактирования максимальной даты.
    QLabel *labelMax = new QLabel("Maximum Date");
    QDateEdit *maxDate = new QDateEdit();
    maxDate->setObjectName("maxDate");
    maxDate->setDate(_maximumDate);
    // Добавить виджет для редактирования минимальной даты.
    QLabel *labelMin = new QLabel("Minimum Date");
    QDateEdit *minDate = new QDateEdit();
    minDate->setObjectName("minDate");
    minDate->setDate(_minimumDate);
    // Добавить виджет для редактирования текущей даты.
    QLabel *labelSel = new QLabel("Selected Date");
    QDateEdit *selectedDate = new QDateEdit();
    selectedDate->setObjectName("selectedDate");
    selectedDate->setDate(_selectedDate);
    // Добавить флаг для редактирования видимости сетки календаря.
    QCheckBox *gridVisible = new QCheckBox();
    gridVisible->setText("Grid Visible");
    gridVisible->setChecked(_gridVisible);
    gridVisible->setObjectName("gridVisible");
    // Добавить выпадающий список для редактирования первого дня недели.
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

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString Calendar::getClassname()
{
    return QString("Calendar");
}
