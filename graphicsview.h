#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "abstractwidget.h"

class GraphicsView : public AbstractWidget
{
public:
    GraphicsView(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);
};

#endif // GRAPHICSVIEW_H
