#ifndef PROGRESSBARVIEW_H
#define PROGRESSBARVIEW_H

#include "abstractwidgetview.h"

/*! \file progressbarview.h
  *
  * \class ProgressBarView
  * \brief ����� ������������� ��������-����.
  * \author ��������� ���������
*/
class ProgressBarView : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ��������-����.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    ProgressBarView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ��������-����.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};
#endif // PROGRESSBARVIEW_H
