#include "tablewidget.h"

TableWidget::TableWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TableWidget_").append(QString::number(numberOfWidget));
    _showGrid = true;
    _rowCount = 0;
    _columnCount = 0;
}

QString TableWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
}

void TableWidget::drawSelf(QGraphicsScene &scene)
{
    TableWidgetView * view = new TableWidgetView(this);
    scene.addItem(view);
}
