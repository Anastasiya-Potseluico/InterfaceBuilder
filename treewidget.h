#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include "abstractitemwidget.h"
#include "treewidgetview.h"

class TreeWidget : public AbstractItemWidget
{
public:
    TreeWidget(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QFile&file);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _headerVisible;
    int _columnCount;
};

#endif // TREEWIDGET_H
