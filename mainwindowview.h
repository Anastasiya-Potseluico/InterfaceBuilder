#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include "abstractwidgetview.h"

/*! \file miainwindowview.h
  *
  * \class MainWindowView
  * \brief ����� ������������� �������� ����.
  * \author ��������� ���������
*/
class MainWindowView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� �������� ����.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    MainWindowView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� �������� ����.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // MAINWINDOWVIEW_H
