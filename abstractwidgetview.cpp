#include "abstractwidgetview.h"

/*
* Конструктор абстрактного представления виджета.
* param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
*/
AbstractWidgetView::AbstractWidgetView(AbstractWidget *drawedWidget)
{
    _drawedWidget = drawedWidget;
    // Устанавливаем флаги для отрисованного виджета.
    setFlags(ItemIsMovable | ItemIsSelectable | ItemSendsScenePositionChanges | ItemIsFocusable);
    // Устанавливаем отрисованный виджет согласно позиции распознанного виджета.
    this->setPos(_drawedWidget->getPosition());
    this->setAcceptHoverEvents(true);
    // Настраиваем уголки изменения размеров виджетов.
    _cornerWidth = 8;
    _cornerHeight = 8;
    // Настраиваем минимально возможный размер виджета.
    _minWidth = 10;
    _minHeight = 10;
}

/*
* Переопределение метода отрисовки представления виджета.
* param [in] painter QPainter.
* param [in] option QStyleOptionGraphicsItem.
* param [in] widget QWidget.
*/
void AbstractWidgetView::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
}

/*
* Метод получения прямоугольника, описанного вокруг представления виджета.
* return Прямоугольник, описанный вокруг представления виджета.
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
* Метод получения размера авиджета с учетом квадратов для изменения размеров виджетов.
* return Прямоугольник, описанный вокруг представления виджета с учетом квадратов для изменения размеров виджетов.
*/
QRectF AbstractWidgetView::widgetSize() const
{
     QSizeF size = _drawedWidget->getSize();
     QPointF p(_cornerWidth,_cornerHeight);
     return QRectF(p, size);
}

/*
* Переопределение метода реагирования на нажатие кнопкой мыши.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
   QGraphicsItem::mousePressEvent(event);
}

/*
* Переопределение метода реагирования на отпускание кнопки мыши.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{  
    // Изменить положение виджета на сцене.
    QPoint p = this->pos().toPoint();
    _drawedWidget->setPosition(p);
    QGraphicsItem::mouseReleaseEvent(event);
}

/*
* Переопределение метода реагирования на движение мышью.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent( event );
    // Проверка границ допустимого размера интерфейса по горизонтали.
    if (x() < 0)
    {
        setPos(0, y());
    }
    else if (x() > 1200 - this->_drawedWidget->getSize().width())
    {
        setPos(1200 - this->_drawedWidget->getSize().width(), y());
    }
    // Проверка границ допустимого размера интерфейса по вертикали.
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
* Переопределение метода реагирования на двойной щелчок кнопкой мыши.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    QMap<QString,QString> settingsMap;
    // Вызов диалогового окна настроек для виджета.
    DialogSettings * settings = new DialogSettings(0, _drawedWidget, &settingsMap);
    QString title = "Настройки виджета ";
    title.append(_drawedWidget->getName());
    settings->setWindowTitle(title);
    settings->exec();
    // Изменение настроек у виджета.
    if(settings->result() == QDialog::Accepted)
    {
        _drawedWidget->setSettings(settingsMap);
        _drawedWidget->emitSettingsChangedSignal();
    }
}

/*
* Переопределение метода реагирования на наведение курсором мыши на объект.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // Отрисовываем уголки изменения размера виджета.
    QColor color (Qt::black);
    _corners[0] = new CornerGrabber(this,0,color);
    _corners[1] = new CornerGrabber(this,1,color);
    _corners[2] = new CornerGrabber(this,2,color);
    _corners[3] = new CornerGrabber(this,3,color);
    // Каждый уголок должен уметь различать события мыши.
    _corners[0]->installSceneEventFilter(this);
    _corners[1]->installSceneEventFilter(this);
    _corners[2]->installSceneEventFilter(this);
    _corners[3]->installSceneEventFilter(this);
    // Установить уголки на виджет.
    setCornerPositions();
}

/*
* Переопределение метода реагирования на снятие курсора мыши с объекта.
* param [in] event Событие мыши.
*/
void AbstractWidgetView::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // Убрать виджета-родителя у уголков.
    _corners[0]->setParentItem(NULL);
    _corners[1]->setParentItem(NULL);
    _corners[2]->setParentItem(NULL);
    _corners[3]->setParentItem(NULL);
    // Освободить память.
    delete _corners[0];
    delete _corners[1];
    delete _corners[2];
    delete _corners[3];
}

/*
* Метод для расстановки квадратов для растягивания виджета.
*/
void AbstractWidgetView::setCornerPositions()
{
    // Расставить квадраты для растягивания по углам виджета.
    QSizeF   size = this->boundingRect().size();
    _corners[0]->setPos(0, 0);
    _corners[1]->setPos(1 + size.width() - _cornerWidth,  0);
    _corners[2]->setPos(1 + size.width() - _cornerWidth,  1 + size.height() - _cornerHeight);
    _corners[3]->setPos(0, 1 + size.height() - _cornerHeight);
}

/*
* Переопределение метода фильтрации событий на сцене.
* param [in] event Событие мыши.
* param [in] watched Участвующий в событии объект.
*/
bool AbstractWidgetView::sceneEventFilter ( QGraphicsItem * watched, QEvent * event )
{
    // Ищем угол, который был зажат.
    CornerGrabber * corner = dynamic_cast<CornerGrabber *>(watched);
    if ( corner == NULL) return false;
    // Ищем событие, которое произошло с углом.
    QGraphicsSceneMouseEvent * mevent = dynamic_cast<QGraphicsSceneMouseEvent*>(event);
    if ( mevent == NULL)
    {
        return false;
    }
    // Реакция на разные события мыши.
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
    // Если мышь двигают с зажатым уголком, нужно изменить размеры виджета.
    if ( corner->getMouseState() == CornerGrabber::MouseMovingState )
    {
        qreal x = mevent->pos().x(), y = mevent->pos().y();
        int XaxisSign = 0;
        int YaxisSign = 0;
        // Высчитываем, какой именно угол зажат.
        switch( corner->getCorner() )
        {
        // Левый верхний угол зажат.
        case 0:
            {
                XaxisSign = +1;
                YaxisSign = +1;
            }
            break;
        // Правый верхний угол зажат.
        case 1:
            {
                XaxisSign = -1;
                YaxisSign = +1;
            }
            break;
        // Правый нижний угол зажат.
        case 2:
            {
                XaxisSign = -1;
                YaxisSign = -1;
            }
            break;
        // Левый нижний угол зажат.
        case 3:
            {
                XaxisSign = +1;
                YaxisSign = -1;
            }
            break;
        }
        // Высчитываем новые размеры виджета и его координаты.
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
        // Учитываем знаки при изменении размера виджета.
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
        // Заново устанавливаем углы для растягивания виджета.
        setCornerPositions();
        this->update();
    }
    return true;
}

/*
* Метод для изменения размеров виджета взависимости от растягивания виджета.
* param [in] x Разница в ширине виджета.
* param [in] y Разница в высоте виджета.
*/
void AbstractWidgetView::adjustSize(int deltaX, int deltaY)
{
    QSize size(_drawedWidget->getSize().width() + deltaX, _drawedWidget->getSize().height() + deltaY);
    _drawedWidget->setSize(size);
}
