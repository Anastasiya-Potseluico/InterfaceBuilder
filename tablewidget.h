#ifndef TABLEWIDGET_H
#define TABLEWIDGET_H

#include "abstractitemwidget.h"
#include "tablewidgetview.h"

class TableWidget : public AbstractItemWidget
{
public:
    TableWidget(QPoint &position, int numberOfWidget);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    bool _showGrid;
    int _rowCount;
    int _columnCount;
};

#endif // TABLEWIDGET_H
