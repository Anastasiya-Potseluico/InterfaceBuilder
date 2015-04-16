#include "abstractitemwidget.h"

AbstractItemWidget::AbstractItemWidget(QPoint &position, QSize &size) : AbstractWidget(position, size)
{
    _autoScroll = true;
    _tabKeyNavigate = false;
}
