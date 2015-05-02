#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "abstractitemwidget.h"
#include "listwidgetview.h"

class ListWidget : public AbstractItemWidget
{
public:
    ListWidget(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    bool _wordWrap;
    bool _sortingEnabled;
};

#endif // LISTWIDGET_H
