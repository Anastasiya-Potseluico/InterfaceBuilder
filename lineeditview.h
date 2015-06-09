#ifndef LINEEDITVIEW_H
#define LINEEDITVIEW_H

#include "abstractwidgetview.h"

/*! \file lineeditview.h
  *
  * \class LineEditView
  * \brief Класс представления виджета строки ввода.
  * \author Поцелуйко Анастасия
*/
class LineEditView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления строки ввода.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    LineEditView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления строки ввода.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LINEEDITVIEW_H
