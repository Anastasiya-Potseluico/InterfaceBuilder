#ifndef AbstractWidgetView_H
#define AbstractWidgetView_H

#include <QGraphicsItem>
#include <QEvent>
#include <QPainter>
#include <QStyle>
#include <QStyleOptionGraphicsItem>

#include "abstractwidget.h"
#include "cornergrabber.h"
#include "dialogsettings.h"

/*! \file abstractwidgetview.h
  *
  * \class AbstractWidgetView
  * \brief ����� ������������ ������������� �������.
  * \author �������� ���������
*/
class AbstractWidgetView : public QGraphicsItem
{

public:
    /*!
    *\brief ����������� ������������ ������������� �������.
    *\param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
    */
    AbstractWidgetView(AbstractWidget *drawedWidget);

    /*!
    *\brief ��������������� ������ ��������� ������������� �������.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /*!
    *\brief ����� ��������� ��������������, ���������� ������ ������������� �������.
    *\return �������������, ��������� ������ ������������� �������.
    */
    QRectF boundingRect() const;

    /*!
    *\brief ����� ��������� ������� �������� � ������ ��������� ��� ��������� �������� ��������.
    *\return �������������, ��������� ������ ������������� ������� � ������ ��������� ��� ��������� �������� ��������.
    */
    QRectF widgetSize() const;

protected:
    /*!\brief ������ ��� ���������*/
    AbstractWidget *_drawedWidget;
    /*!\brief ����� ������������� �������*/
    QGraphicsTextItem _itemText;
    /*!\brief ������ ��������� ��������� �������� �������*/
    CornerGrabber*  _corners[4];

    /*!
    *\brief ��������������� ������ ������������ �� ������� ������� ����.
    *\param [in] event ������� ����.
    */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief ��������������� ������ ������������ �� ���������� ������ ����.
    *\param [in] event ������� ����.
    */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief ��������������� ������ ������������ �� �������� �����.
    *\param [in] event ������� ����.
    */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief ��������������� ������ ������������ �� ������� ������ ������� ����.
    *\param [in] event ������� ����.
    */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief ��������������� ������ ������������ �� ��������� �������� ���� �� ������.
    *\param [in] event ������� ����.
    */
    void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );

    /*!
    *\brief ��������������� ������ ���������� ������� �� �����.
    *\param [in] event ������� ����.
    *\param [in] watched ����������� � ������� ������.
    */
    bool sceneEventFilter ( QGraphicsItem * watched, QEvent * event );

    /*!
    *\brief ��������������� ������ ������������ �� ������ ������� ���� � �������.
    *\param [in] event ������� ����.
    */
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );

private:
    /*!\brief ������ ��������� ��������� �������� �������*/
    int _cornerWidth;
    /*!\brief ������ ��������� ��� ��������� �������� ��������*/
    int _cornerHeight;

    /*!\brief ���������� ��������� ������ �������*/
    int _minWidth;
    /*!\brief ���������� ��������� ������ �������*/
    int _minHeight;

    /*!
    *\brief ����� ��� ����������� ��������� ��� ������������ �������.
    */
    void setCornerPositions();

    /*!
    *\brief ����� ��� ��������� �������� ������� ������������ �� ������������ �������.
    *\param [in] x ������� � ������ �������.
    *\param [in] y ������� � ������ �������.
    */
    void adjustSize(int deltaX, int deltaY);

};

#endif // AbstractWidgetView_H
