#ifndef LISTWIDGETVIEW_H
#define LISTWIDGETVIEW_H

#include "abstractwidgetview.h"

/*! \file listwidgetview.h
  *
  * \class ListWidgetView
  * \brief ����� ������������� ������� ������.
  * \author ��������� ���������
*/
class ListWidgetView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    ListWidgetView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // LISTWIDGETVIEW_H
