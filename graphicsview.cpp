#include "graphicsview.h"

GraphicsView::GraphicsView(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(256,192)))
{

}

void GraphicsView::drawSelf(QGraphicsScene &scene)
{

}

QString GraphicsView::writeSelfIntoFile(QFile &file)
{

}
