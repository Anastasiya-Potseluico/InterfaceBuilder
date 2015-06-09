#ifndef LABELVIEW_H
#define LABELVIEW_H

#include "abstractwidgetview.h"

/*! \file labelview.h
  *
  * \class LabelView
  * \brief Класс представления лейбла.
  * \author Поцелуйко Анастасия
*/
class LabelView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления лейбла.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    LabelView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления лейбла.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LABELVIEW_H
