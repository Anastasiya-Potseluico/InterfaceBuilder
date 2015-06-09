#ifndef GRAPHICSVIEWVIEW_H
#define GRAPHICSVIEWVIEW_H

#include "abstractwidgetview.h"

/*! \file graphiscviewview.h
  *
  * \class GraphicsViewView
  * \brief ����� ������������� ������� ����������.
  * \author ��������� ���������
*/
class GraphicsViewView  : public AbstractWidgetView
{
public:
    /*!
    *\brief ����������� ������������� ����������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    GraphicsViewView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� ����������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
};

#endif // GRAPHICSVIEWVIEW_H
