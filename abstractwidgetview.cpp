#include "abstractwidgetview.h"

/*
* ����������� ������������ ������������� �������.
* param [in] drawedWidget ��������� �� ������, ������� ����� ��������������.
*/
AbstractWidgetView::AbstractWidgetView(AbstractWidget *drawedWidget)
{
    _drawedWidget = drawedWidget;
    // ������������� ����� ��� ������������� �������.
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges | ItemIsFocusable);
    // ������������� ������������ ������ �������� ������� ������������� �������.
    this->setPos(_drawedWidget->getPosition());
    this->setAcceptHoverEvents(true);
    // ����������� ������ ��������� �������� ��������.
    _cornerWidth = 8;
    _cornerHeight = 8;
    // ����������� ���������� ��������� ������ �������.
    _minWidth = 10;
    _minHeight = 10;
}

/*
* ��������������� ������ ��������� ������������� �������.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void AbstractWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

/*
* ����� ��������� ��������������, ���������� ������ ������������� �������.
* return �������������, ��������� ������ ������������� �������.
*/
QRectF AbstractWidgetView::boundingRect() const
{
    QSizeF size = _drawedWidget->getSize();
    size.setWidth(size.width()+_cornerWidth*2);
    size.setHeight(size.height()+_cornerHeight*2);
    QPointF p(0.0,0.0);
    return QRectF(p, size);
}

/*
* ����� ��������� ������� �������� � ������ ��������� ��� ��������� �������� ��������.
* return �������������, ��������� ������ ������������� ������� � ������ ��������� ��� ��������� �������� ��������.
*/
QRectF AbstractWidgetView::widgetSize() const
{
     QSizeF size = _drawedWidget->getSize();
     QPointF p(_cornerWidth,_cornerHeight);
     return QRectF(p, size);
}

/*
* ��������������� ������ ������������ �� ������� ������� ����.
* param [in] event ������� ����.
*/
void AbstractWidgetView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsItem::mousePressEvent(event);
}

/*
* ��������������� ������ ������������ �� ���������� ������ ����.
* param [in] event ������� ����.
*/
void AbstractWidgetView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  
    // �������� ��������� ������� �� �����.
    QPoint p = this->pos().toPoint();
    _drawedWidget->setPosition(p);
    QGraphicsItem::mouseReleaseEvent(event);
}

/*
* ��������������� ������ ������������ �� �������� �����.
* param [in] event ������� ����.
*/
void AbstractWidgetView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent( event );
    // �������� ������ ����������� ������� ���������� �� �����������.
    if (x() < 0)
    {
        setPos(0, y());
    }
    else if (x() > 1200 - this->_drawedWidget->getSize().width())
    {
        setPos(1200 - this->_drawedWidget->getSize().width(), y());
    }
    // �������� ������ ����������� ������� ���������� �� ���������.
    if (y() < 0)
    {
        setPos(x(), 0);
    }
    else if (y() > 1200 - this->_drawedWidget->getSize().height())
    {
        setPos(x(), 1200 - this->_drawedWidget->getSize().height());
    }
}

/*
* ��������������� ������ ������������ �� ������� ������ ������� ����.
* param [in] event ������� ����.
*/
void AbstractWidgetView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QMap<QString,QString> settingsMap;
    // ����� ����������� ���� �������� ��� �������.
    DialogSettings * settings = new DialogSettings(0, _drawedWidget, &settingsMap);
    QString title = "��������� ������� ";
    title.append(_drawedWidget->getName());
    settings->setWindowTitle(title);
    settings->exec();
    // ��������� �������� � �������.
    if(settings->result() == QDialog::Accepted)
    {
        _drawedWidget->setSettings(settingsMap);
        _drawedWidget->emitSettingsChangedSignal();
    }
}

/*
* ��������������� ������ ������������ �� ��������� �������� ���� �� ������.
* param [in] event ������� ����.
*/
void AbstractWidgetView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // ������������ ������ ��������� ������� �������.
    QColor color (Qt::black);
    _corners[0] = new CornerGrabber(this,0,color);
    _corners[1] = new CornerGrabber(this,1,color);
    _corners[2] = new CornerGrabber(this,2,color);
    _corners[3] = new CornerGrabber(this,3,color);
    // ������ ������ ������ ����� ��������� ������� ����.
    _corners[0]->installSceneEventFilter(this);
    _corners[1]->installSceneEventFilter(this);
    _corners[2]->installSceneEventFilter(this);
    _corners[3]->installSceneEventFilter(this);
    // ���������� ������ �� ������.
    setCornerPositions();
}

/*
* ��������������� ������ ������������ �� ������ ������� ���� � �������.
* param [in] event ������� ����.
*/
void AbstractWidgetView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // ������ �������-�������� � �������.
    _corners[0]->setParentItem(NULL);
    _corners[1]->setParentItem(NULL);
    _corners[2]->setParentItem(NULL);
    _corners[3]->setParentItem(NULL);
    // ���������� ������.
    delete _corners[0];
    delete _corners[1];
    delete _corners[2];
    delete _corners[3];
}

/*
* ����� ��� ����������� ��������� ��� ������������ �������.
*/
void AbstractWidgetView::setCornerPositions()
{
    // ���������� �������� ��� ������������ �� ����� �������.
    QSizeF   size = this->boundingRect().size();
    _corners[0]->setPos(0, 0);
    _corners[1]->setPos(1 + size.width() - _cornerWidth,  0);
    _corners[2]->setPos(1 + size.width() - _cornerWidth,  1 + size.height() - _cornerHeight);
    _corners[3]->setPos(0, 1 + size.height() - _cornerHeight);
}

/*
* ��������������� ������ ���������� ������� �� �����.
* param [in] event ������� ����.
* param [in] watched ����������� � ������� ������.
*/
bool AbstractWidgetView::sceneEventFilter ( QGraphicsItem * watched, QEvent * event )
{
    // ���� ����, ������� ��� �����.
    CornerGrabber * corner = dynamic_cast<CornerGrabber *>(watched);
    if ( corner == NULL) return false;
    // ���� �������, ������� ��������� � �����.
    QGraphicsSceneMouseEvent * mevent = dynamic_cast<QGraphicsSceneMouseEvent*>(event);
    if ( mevent == NULL)
    {
        return false;
    }
    // ������� �� ������ ������� ����.
    switch (event->type())
    {
        case QEvent::GraphicsSceneMousePress:
            {
                corner->setMouseState(CornerGrabber::MouseDownState);
                corner->mouseDownX = mevent->pos().x();
                corner->mouseDownY = mevent->pos().y();
            }
            break;
        case QEvent::GraphicsSceneMouseRelease:
            {
                corner->setMouseState(CornerGrabber::mouseReleasedState);
            }
            break;
        case QEvent::GraphicsSceneMouseMove:
            {
                corner->setMouseState(CornerGrabber::MouseMovingState );
            }
            break;
        default:
            return false;
            break;
    }
    // ���� ���� ������� � ������� �������, ����� �������� ������� �������.
    if ( corner->getMouseState() == CornerGrabber::MouseMovingState )
    {
        qreal x = mevent->pos().x(), y = mevent->pos().y();
        int XaxisSign = 0;
        int YaxisSign = 0;
        // �����������, ����� ������ ���� �����.
        switch( corner->getCorner() )
        {
        // ����� ������� ���� �����.
        case 0:
            {
                XaxisSign = +1;
                YaxisSign = +1;
            }
            break;
        // ������ ������� ���� �����.
        case 1:
            {
                XaxisSign = -1;
                YaxisSign = +1;
            }
            break;
        // ������ ������ ���� �����.
        case 2:
            {
                XaxisSign = -1;
                YaxisSign = -1;
            }
            break;
        // ����� ������ ���� �����.
        case 3:
            {
                XaxisSign = +1;
                YaxisSign = -1;
            }
            break;
        }
        // ����������� ����� ������� ������� � ��� ����������.
        int xMoved = corner->mouseDownX - x;
        int yMoved = corner->mouseDownY - y;

        int newWidth = this->_drawedWidget->getSize().width() + ( XaxisSign * xMoved);
        if ( newWidth < _minWidth ) newWidth  = _minWidth;

        int newHeight = this->_drawedWidget->getSize().height() + (YaxisSign * yMoved) ;
        if ( newHeight < _minHeight ) newHeight = _minHeight;

        int deltaWidth  =   newWidth - this->_drawedWidget->getSize().width() ;
        int deltaHeight =   newHeight - this->_drawedWidget->getSize().height() ;

        adjustSize(deltaWidth, deltaHeight);

        deltaWidth *= (-1);
        deltaHeight *= (-1);
        // ��������� ����� ��� ��������� ������� �������.
        if (corner->getCorner() == 0 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(newXpos, newYpos);
        }
        else   if (corner->getCorner() == 1 )
        {
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(this->pos().x(), newYpos);
        }
        else   if (corner->getCorner() == 3 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            this->setPos(newXpos,this->pos().y());
        }
        // ������ ������������� ���� ��� ������������ �������.
        setCornerPositions();
        this->update();
    }
    return true;
}

/*
* ����� ��� ��������� �������� ������� ������������ �� ������������ �������.
* param [in] x ������� � ������ �������.
* param [in] y ������� � ������ �������.
*/
void AbstractWidgetView::adjustSize(int deltaX, int deltaY)
{
    QSize size(_drawedWidget->getSize().width() + deltaX, _drawedWidget->getSize().height() + deltaY);
    _drawedWidget->setSize(size);
}
