#ifndef GRAPHICSVIEWVIEW_H
#define GRAPHICSVIEWVIEW_H

#include "abstractwidgetview.h"

/*! \file graphiscviewview.h
  *
  * \class GraphicsViewView
  * \brief Класс представления виджета графиксвью.
  * \author Поцелуйко Анастасия
*/
class GraphicsViewView  : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления графиксвью.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    GraphicsViewView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления графиксвью.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // GRAPHICSVIEWVIEW_H
