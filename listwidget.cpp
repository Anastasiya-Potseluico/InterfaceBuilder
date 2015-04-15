#include "listwidget.h"

ListWidget::ListWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("ListWidget_").append(QString::number(numberOfWidget));
    _sortingEnabled = true;
    _wordWrap = true;
}

QString ListWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
}

void ListWidget::drawSelf(QGraphicsScene &scene)
{
    ListWidgetView * view = new ListWidgetView(this);
    scene.addItem(view);
}

