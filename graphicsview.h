#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "abstractwidget.h"
#include "graphicsviewview.h"

enum NEEDED_SCROLL_PANELS {always_on, always_off, as_needed};

class GraphicsView : public AbstractWidget
{
public:
    GraphicsView(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _interactive;
    NEEDED_SCROLL_PANELS _verticalScrollPanel;
    NEEDED_SCROLL_PANELS _horizontalScrollPanel;
};

#endif // GRAPHICSVIEW_H
