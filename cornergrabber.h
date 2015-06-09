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
  * \brief Класс угла изменения размера виджета.
  * \author Поцелуко Анастасия
*/
class CornerGrabber : public QGraphicsItem
{

public:
    /*!
    *\brief Конструктор угла.
    *\param [in] parent Указатель на родительский виджет.
    *\param [in] corner Тип угла.
    *\param [in] color Цвет угла.
    */
    CornerGrabber(QGraphicsItem *parent = 0,  int corner=0, QColor &color = *new QColor());

    /*!
    *\brief Метод получения типа угла.
    *\return Тип угла (0 - левый верхний, далее с 1 по 3 высчитываются по часовой стрелке).
    */
    int  getCorner();

    /*!
    *\brief Метод для установки состояния мыши.
    *\param [in] parent Указатель на родительский виджет.
    */
    void setMouseState(int s);

    /*!
    *\brief Метод получения состояния мыши.
    *\return Состояние мыши.
    */
    int  getMouseState();

    /*!\brief Координата зажатой кнопки мыши по оси х*/
    qreal mouseDownX;
    /*!\brief Координата зажатой кнопки мыши по оси у*/
    qreal mouseDownY;
    /*!\brief Перечисление возможных состояний мыши*/
    enum mouseStates {mouseReleasedState, MouseDownState, MouseMovingState};

private:
    // Переопределенные методы из класса QGraphicsItem.
    virtual QRectF boundingRect() const;
    virtual void paint (QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    virtual void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );
    virtual void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );
    virtual void mouseMoveEvent ( QGraphicsSceneMouseEvent * event );
    virtual void mouseMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent * event );
    virtual void mousePressEvent(QGraphicsSceneDragDropEvent *event);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent * event );

    /*!\brief Цвет угла*/
    QColor _outterborderColor;
    /*!\brief Кисть для отрисовки угла*/
    QPen _outterborderPen;
    /*!\brief Родительский виджет*/
    QGraphicsItem *_parentItem;
    /*!\brief Тип угла*/
    int _corner;
    /*!\brief Ширина угла*/
    qreal   _width;
    /*!\brief Высота угла*/
    qreal   _height;
    /*!\brief Текущее состояние мыши*/
    int _mouseButtonState;
};

#endif // CORNERGRABBER_H
