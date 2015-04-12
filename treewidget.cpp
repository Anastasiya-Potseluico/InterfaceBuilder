#include "treewidget.h"

TreeWidget::TreeWidget(QPoint &position, int numberOfWidget): AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TreeWidget_").append(QString::number(numberOfWidget));
    _headerVisible = true;
    _columnCount = 1;
}

QString TreeWidget::writeSelfIntoFile(QFile &file)
{
}

void TreeWidget::drawSelf(QGraphicsScene &scene)
{
    TreeWidgetView * view = new TreeWidgetView(this);
    scene.addItem(view);
}
