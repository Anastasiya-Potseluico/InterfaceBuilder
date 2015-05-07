#include "abstractwidgetview.h"


AbstractWidgetView::AbstractWidgetView(AbstractWidget *drawedWidget)
{
    _drawedWidget = drawedWidget;
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges | ItemIsFocusable);
    this->setPos(_drawedWidget->getPosition());
    this->setAcceptHoverEvents(true);
    cornerWidth = 6;
    cornerHeight = 6;
    _minWidth = 10;
    _minHeight = 10;
}

void AbstractWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

QRectF AbstractWidgetView::boundingRect() const
{
    QSizeF size = _drawedWidget->getSize();
    size.setWidth(size.width()+cornerWidth*2);
    size.setHeight(size.height()+cornerHeight*2);
    QPointF p(0.0,0.0);
    return QRectF(p, size);
}

QRectF AbstractWidgetView::widgetSize() const
{
     QSizeF size = _drawedWidget->getSize();
     QPointF p(cornerWidth,cornerHeight);
     return QRectF(p, size);
}

void AbstractWidgetView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsItem::mousePressEvent(event);
}

void AbstractWidgetView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  
    QPoint p = this->pos().toPoint();
    _drawedWidget->setPosition(p);
    QGraphicsItem::mouseReleaseEvent( event );
}

void AbstractWidgetView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent( event );
    if (x() < 0)
    {
        setPos(0, y());
    }
    else if (x() > 1200 - this->_drawedWidget->getSize().width())
    {
        setPos(1200 - this->_drawedWidget->getSize().width(), y());
    }

    if (y() < 0)
    {
        setPos(x(), 0);
    }
    else if (y() > 1200 - this->_drawedWidget->getSize().height())
    {
        setPos(x(), 1200 - this->_drawedWidget->getSize().height());
    }
}

void AbstractWidgetView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QMap<QString,QString> settingsMap;
    DialogSettings * settings = new DialogSettings(0,_drawedWidget,&settingsMap);
    QString title = "Настройки виджета ";
    title.append(_drawedWidget->getName());
    settings->setWindowTitle(title);
    int res = settings->exec();
    if(settings->result() == QDialog::Accepted)
    {
        _drawedWidget->setSettings(settingsMap);
        // Send signal to mainWindow
        _drawedWidget->emitSettingsChangedSignal();

    }
}

void AbstractWidgetView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{

    QColor color (Qt::black);
    _corners[0] = new CornerGrabber(this,0,color);
    _corners[1] = new CornerGrabber(this,1,color);
    _corners[2] = new CornerGrabber(this,2,color);
    _corners[3] = new CornerGrabber(this,3,color);


    _corners[0]->installSceneEventFilter(this);
    _corners[1]->installSceneEventFilter(this);
    _corners[2]->installSceneEventFilter(this);
    _corners[3]->installSceneEventFilter(this);

    setCornerPositions();
}

void AbstractWidgetView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{

    _corners[0]->setParentItem(NULL);
    _corners[1]->setParentItem(NULL);
    _corners[2]->setParentItem(NULL);
    _corners[3]->setParentItem(NULL);

    delete _corners[0];
    delete _corners[1];
    delete _corners[2];
    delete _corners[3];
}

void AbstractWidgetView::setCornerPositions()
{

    QPointF pos = this->scenePos();
    QSizeF   size = this->boundingRect().size();
    int posX, posY;
    posX = pos.x();
    posX = pos.x() + size.width()-cornerWidth;
    posY = pos.y();
    posY = pos.y() + size.height()-cornerHeight;
    _corners[0]->setPos(0, 0);
    _corners[1]->setPos(1 + size.width()-cornerWidth,  0);
    _corners[2]->setPos(1 + size.width() - cornerWidth,  1 + size.height()-cornerHeight);
    _corners[3]->setPos(0, 1 + size.height()-cornerHeight);
}

bool AbstractWidgetView::sceneEventFilter ( QGraphicsItem * watched, QEvent * event )
{

    CornerGrabber * corner = dynamic_cast<CornerGrabber *>(watched);
    if ( corner == NULL) return false;

    QGraphicsSceneMouseEvent * mevent = dynamic_cast<QGraphicsSceneMouseEvent*>(event);
    if ( mevent == NULL)
    {
        return false;
    }


    switch (event->type() )
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


    if ( corner->getMouseState() == CornerGrabber::MouseMovingState )
    {

        qreal x = mevent->pos().x(), y = mevent->pos().y();

        int XaxisSign = 0;
        int YaxisSign = 0;
        switch( corner->getCorner() )
        {
        case 0:
            {
                XaxisSign = +1;
                YaxisSign = +1;
            }
            break;

        case 1:
            {
                XaxisSign = -1;
                YaxisSign = +1;
            }
            break;

        case 2:
            {
                XaxisSign = -1;
                YaxisSign = -1;
            }
            break;

        case 3:
            {
                XaxisSign = +1;
                YaxisSign = -1;
            }
            break;

        }
        int xMoved = corner->mouseDownX - x;
        int yMoved = corner->mouseDownY - y;

        int newWidth = this->_drawedWidget->getSize().width() + ( XaxisSign * xMoved);
        if ( newWidth < _minWidth ) newWidth  = _minWidth;

        int newHeight = this->_drawedWidget->getSize().height() + (YaxisSign * yMoved) ;
        if ( newHeight < _minHeight ) newHeight = _minHeight;

        int deltaWidth  =   newWidth - this->_drawedWidget->getSize().width() ;
        int deltaHeight =   newHeight - this->_drawedWidget->getSize().height() ;

        adjustSize(  deltaWidth ,   deltaHeight);

        deltaWidth *= (-1);
        deltaHeight *= (-1);

        if ( corner->getCorner() == 0 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(newXpos, newYpos);
        }
        else   if ( corner->getCorner() == 1 )
        {
            int newYpos = this->pos().y() + deltaHeight;
            this->setPos(this->pos().x(), newYpos);
        }
        else   if ( corner->getCorner() == 3 )
        {
            int newXpos = this->pos().x() + deltaWidth;
            this->setPos(newXpos,this->pos().y());
        }

        setCornerPositions();

        this->update();
    }

    return true;
}


void AbstractWidgetView::adjustSize(int x, int y)
{
    QSize size(_drawedWidget->getSize().width() + x, _drawedWidget->getSize().height() + y);
    _drawedWidget->setSize(size);
}
