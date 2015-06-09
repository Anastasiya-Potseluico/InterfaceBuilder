#ifndef CALENDARVIEW_H
#define CALENDARVIEW_H

#include "abstractwidgetview.h"

/*! \file calendarview.h
  *
  * \class Calendar
  * \brief Класс представления виджета календаря.
  * \author Поцелуко Анастасия
*/
class CalendarView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления календаря.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    CalendarView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления календаря.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CALENDARVIEW_H
