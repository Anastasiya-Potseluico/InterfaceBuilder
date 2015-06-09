#ifndef CALENDAR_H
#define CALENDAR_H

#include <QComboBox>
#include <QDate>
#include <QDateEdit>

#include "abstractwidget.h"
#include "calendarview.h"

enum weekDays {monday, tuesday, wednesday, thursday, friday, saturday, sunday};

/*! \file calendar.h
  *
  * \class Calendar
  * \brief Класс виджета календаря.
  * \author Поцелуко Анастасия
*/
class Calendar : public AbstractWidget
{
public:
    /*!
    *\brief Конструктор календаря.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    Calendar(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи календаря в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки календаря.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для календаря.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод для добавления нужных виджетов настроек для календаря в диалоговом окне.
    */
    void addWidgetsForSettings();

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

private:
     /*!\brief Выбранная дата*/
    QDate _selectedDate;
     /*!\brief Минимальная дата*/
    QDate _minimumDate;
     /*!\brief Максимальная дата*/
    QDate _maximumDate;
     /*!\brief Первый день недели для отображения*/
    weekDays _firstWeekDay;
     /*!\brief Видимость сетки календаря*/
    bool _gridVisible;
};

#endif // CALENDAR_H
