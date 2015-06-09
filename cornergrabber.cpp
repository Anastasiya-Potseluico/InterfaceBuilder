#include "cornergrabber.h"

/*
* Конструктор угла.
* param [in] parent Указатель на родительский виджет.
* param [in] corner Тип угла.
* param [in] color Цвет угла.
*/
CornerGrabber::CornerGrabber(QGraphicsItem *parent,  int corner, QColor &color)
{
    setParentItem(parent);
    _corner = corner;
    _outterborderPen.setWidth(2);
    _outterborderPen.setColor(color);
    _parentItem = parent;
    _width = 8;
    _height = 8;
    _mouseButtonState = mouseReleasedState;
   this->setAcceptHoverEvents(true);
}

/*
* Метод для установки состояния мыши.
* param [in] parent Указатель на родительский виджет.
*/
void CornerGrabber::setMouseState(int s)
{
    _mouseButtonState = s;
}

/*
* Метод получения состояния мыши.
* return Состояние мыши.
*/
int CornerGrabber::getMouseState()
{
    return _mouseButtonState;
}

/*
* Метод получения типа угла.
* return Тип угла (0 - левый верхний, далее с 1 по 3 высчитываются по часовой стрелке).
*/
int CornerGrabber::getCorner()
{
    return _corner;
}

void CornerGrabber::mouseMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

void CornerGrabber::mousePressEvent(QGraphicsSceneDragDropEvent *event)
{
    event->setAccepted(false);
}

void CornerGrabber::mouseReleaseEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(true);
}

void CornerGrabber::mousePressEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(false);
}

void CornerGrabber::mouseMoveEvent ( QGraphicsSceneMouseEvent * event )
{
    event->setAccepted(false);
}

void CornerGrabber::hoverLeaveEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::black;
    this->update(0,0,_width,_height);
}

void CornerGrabber::hoverEnterEvent ( QGraphicsSceneHoverEvent * )
{
    _outterborderColor = Qt::red;
    this->update(0,0,_width,_height);
}

QRectF CornerGrabber::boundingRect() const
{
     return QRectF(0,0,_width,_height);
}

void CornerGrabber::paint (QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    _outterborderPen.setCapStyle(Qt::SquareCap);
    _outterborderPen.setStyle(Qt::SolidLine);
    painter->setPen(_outterborderPen);

    QPointF topLeft (0, 0);
    QPointF bottomRight (_width, _height);

    QRectF rect (topLeft, bottomRight);

    QBrush brush (Qt::SolidPattern);
    brush.setColor (_outterborderColor);
    painter->fillRect(rect,brush);
}
