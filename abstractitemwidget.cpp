#include "abstractitemwidget.h"

/*
* ����������� ������������ ������ ������.
* param [in] position ������ �� �������, ������� ������ ������ ������.
* param [in] size ������ ������������ �������.
*/
AbstractItemWidget::AbstractItemWidget(QPoint &position, QSize &size) : AbstractWidget(position, size)
{
    // ��������� ������ �� ���������.
    _autoScroll = true;
    _tabKeyNavigate = false;
}

