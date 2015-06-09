#ifndef CHECKBOXVIEW_H
#define CHECKBOXVIEW_H

#include "abstractwidgetview.h"

/*! \file checkboxview.h
  *
  * \class CheckBoxView
  * \brief ����� ������������� ������� ��������.
  * \author �������� ���������
*/
class CheckBoxView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ��������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    CheckBoxView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ��������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // CHECKBOXVIEW_H
