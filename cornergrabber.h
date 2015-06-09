#ifndef CORNERGRABBER_H
#define CORNERGRABBER_H

#include <QColor>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsTextItem>
#include <QObject>
#include <QPainter>
#include <QPen>
#include <QPointF>

/*! \file cornergrabber.h
  *
  * \class CornerGrabber
  * \brief ����� ���� ��������� ������� �������.
  * \author �������� ���������
*/
class CornerGrabber : public QGraphicsItem
{

public:
    /*!
    *\brief ����������� ����.
    *\param [in] parent ��������� �� ������������ ������.
    *\param [in] corner ��� ����.
    *\param [in] color ���� ����.
    */
    CornerGrabber(QGraphicsItem *parent = 0,  int corner=0, QColor &color = *new QColor());

    /*!
    *\brief ����� ��������� ���� ����.
    *\return ��� ���� (0 - ����� �������, ����� � 1 �� 3 ������������� �� ������� �������).
    */
    int  getCorner();

    /*!
    *\brief ����� ��� ��������� ��������� ����.
    *\param [in] parent ��������� �� ������������ ������.
    */
    void setMouseState(int s);

    /*!
    *\brief ����� ��������� ��������� ����.
    *\return ��������� ����.
    */
    int  getMouseState();

    /*!\brief ���������� ������� ������ ���� �� ��� �*/
    qreal mouseDownX;
    /*!\brief ���������� ������� ������ ���� �� ��� �*/
    qreal mouseDownY;
    /*!\brief ������������ ��������� ��������� ����*/
    enum mouseStates {mouseReleasedState, MouseDownState, MouseMovingState};

private:
    // ���������������� ������ �� ������ QGraphicsItem.
    virtual QRectF boundingRect() const;
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );
    virtual void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent * event );
    virtual void mousePressEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );

    /*!\brief ���� ����*/
    QColor _outterborderColor;
    /*!\brief ����� ��� ��������� ����*/
    QPen _outterborderPen;
    /*!\brief ������������ ������*/
    QGraphicsItem *_parentItem;
    /*!\brief ��� ����*/
    int _corner;
    /*!\brief ������ ����*/
    qreal   _width;
    /*!\brief ������ ����*/
    qreal   _height;
    /*!\brief ������� ��������� ����*/
    int _mouseButtonState;
};

#endif // CORNERGRABBER_H
