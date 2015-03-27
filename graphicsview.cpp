#include "graphicsview.h"

GraphicsView::GraphicsView(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(256,192)))
{
    _interactive = false;
    _verticalScrollPanel = as_needed;
    _horizontalScrollPanel = as_needed;
    _name = QString("GraphicsView").append(QString::number(numberOfWidget));
}

void GraphicsView::drawSelf(QGraphicsScene &scene)
{
    GraphicsViewView * view = new GraphicsViewView(this);
    scene.addItem(view);
}

QString GraphicsView::writeSelfIntoFile(QFile &file)
{

}
