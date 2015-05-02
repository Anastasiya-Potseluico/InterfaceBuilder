#ifndef AbstractWidgetView_H
#define AbstractWidgetView_H

#include "abstractwidget.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QStyle>
#include <QEvent>
#include <QStyleOptionGraphicsItem>
#include "cornergrabber.h"
#include "dialogsettings.h"


class AbstractWidgetView : public QGraphicsItem
{
public:
    AbstractWidgetView(AbstractWidget *drawedWidget);
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);
    QRectF boundingRect() const;
    QRectF widgetSize() const;

protected:
    AbstractWidget *_drawedWidget;
    QGraphicsTextItem _itemText;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );
    bool sceneEventFilter ( QGraphicsItem * watched, QEvent * event );
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );
    CornerGrabber*  _corners[4]; // Уголки изменения размера виджета
    void setCornerPositions();
    void adjustSize(int x, int y);

private:
    int cornerWidth;
    int cornerHeight;

    int _minWidth;
    int _minHeight;

};

#endif // AbstractWidgetView_H
