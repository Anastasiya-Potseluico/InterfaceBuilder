#ifndef PROGRESSBARVIEW_H
#define PROGRESSBARVIEW_H

#include "abstractwidgetview.h"

/*! \file progressbarview.h
  *
  * \class ProgressBarView
  * \brief Класс представления прогресс-бара.
  * \author Поцелуйко Анастасия
*/
class ProgressBarView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления прогресс-бара.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    ProgressBarView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления прогресс-бара.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // PROGRESSBARVIEW_H
