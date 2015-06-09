#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include "abstractwidgetview.h"

/*! \file miainwindowview.h
  *
  * \class MainWindowView
  * \brief Класс представления главного окна.
  * \author Поцелуйко Анастасия
*/
class MainWindowView : public AbstractWidgetView
{
public:
    /*!
    *\brief Конструктор представления главного окна.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    MainWindowView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления главного окна.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // MAINWINDOWVIEW_H
