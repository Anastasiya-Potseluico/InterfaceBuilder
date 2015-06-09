#ifndef LISTWIDGETVIEW_H
#define LISTWIDGETVIEW_H

#include "abstractwidgetview.h"

/*! \file listwidgetview.h
  *
  * \class ListWidgetView
  * \brief Класс представления виджета списка.
  * \author Поцелуйко Анастасия
*/
class ListWidgetView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления списка.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    ListWidgetView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления списка.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // LISTWIDGETVIEW_H
