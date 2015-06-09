#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include "abstractwidgetview.h"

/*! \file calendarview.h
  *
  * \class Calendar
  * \brief ����� ������������� ������� ���������.
  * \author �������� ���������
*/
class CalendarView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ���������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    CalendarView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ���������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CALENDARVIEW_H
