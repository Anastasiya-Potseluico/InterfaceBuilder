#ifndef LINEEDITVIEW_H
#define LINEEDITVIEW_H

#include "abstractwidgetview.h"

/*! \file lineeditview.h
  *
  * \class LineEditView
  * \brief ����� ������������� ������� ������ �����.
  * \author ��������� ���������
*/
class LineEditView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ������ �����.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    LineEditView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ������ �����.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LINEEDITVIEW_H
