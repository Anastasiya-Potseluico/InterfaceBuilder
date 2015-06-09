#ifndef COMBOBOXVIEW_H
#define COMBOBOXVIEW_H

#include "abstractwidgetview.h"

/*! \file comboboxview.h
  *
  * \class ComboBoxView
  * \brief ����� ������������� ������� ����������.
  * \author �������� ���������
*/
class ComboBoxView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ����������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    ComboBoxView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ����������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // COMBOBOXVIEW_H
