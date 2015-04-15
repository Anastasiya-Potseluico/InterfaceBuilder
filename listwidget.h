#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "abstractitemwidget.h"
#include "listwidgetview.h"

class ListWidget : public AbstractItemWidget
{
public:
    ListWidget(QPoint &position, int numberOfWidget);
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    bool _wordWrap;
    bool _sortingEnabled;
};

#endif // LISTWIDGET_H
