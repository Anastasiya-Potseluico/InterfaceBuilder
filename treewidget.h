#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include "abstractitemwidget.h"
#include "treewidgetview.h"

class TreeWidget : public AbstractItemWidget
{
public:
    TreeWidget(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    bool _headerVisible;
    int _columnCount;
};

#endif // TREEWIDGET_H
