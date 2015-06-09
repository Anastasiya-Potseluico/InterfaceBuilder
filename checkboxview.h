#ifndef CHECKBOXVIEW_H
#define CHECKBOXVIEW_H

#include "abstractwidgetview.h"

/*! \file checkboxview.h
  *
  * \class CheckBoxView
  * \brief Класс представления виджета чекбокса.
  * \author Поцелуко Анастасия
*/
class CheckBoxView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления чекбокса.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    CheckBoxView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления чекбокса.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CHECKBOXVIEW_H
