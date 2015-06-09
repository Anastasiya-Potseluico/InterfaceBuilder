#ifndef LABELVIEW_H
#define LABELVIEW_H

#include "abstractwidgetview.h"

/*! \file labelview.h
  *
  * \class LabelView
  * \brief ����� ������������� ������.
  * \author ��������� ���������
*/
class LabelView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    LabelView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // LABELVIEW_H
