#ifndef COMBOBOXVIEW_H
#define COMBOBOXVIEW_H

#include "abstractwidgetview.h"

/*! \file comboboxview.h
  *
  * \class ComboBoxView
  * \brief Класс представления виджета комбобокса.
  * \author Поцелуко Анастасия
*/
class ComboBoxView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления комбобокса.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    ComboBoxView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления комбобокса.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // COMBOBOXVIEW_H
