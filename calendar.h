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
  * \brief ����� ������� ���������.
  * \author �������� ���������
*/
class Calendar : public AbstractWidget
{
public:
    /*!
    *\brief ����������� ���������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    Calendar(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ ��������� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ���������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ���������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ��������� � ���������� ����.
    */
    void addWidgetsForSettings();

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

private:
     /*!\brief ��������� ����*/
    QDate _selectedDate;
     /*!\brief ����������� ����*/
    QDate _minimumDate;
     /*!\brief ������������ ����*/
    QDate _maximumDate;
     /*!\brief ������ ���� ������ ��� �����������*/
    weekDays _firstWeekDay;
     /*!\brief ��������� ����� ���������*/
    bool _gridVisible;
};

#endif // CALENDAR_H
