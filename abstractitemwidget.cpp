#include "abstractitemwidget.h"

/*
* Конструктор абстрактного списка данных.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
AbstractItemWidget::AbstractItemWidget(QPoint &position, QSize &size) : AbstractWidget(position, size)
{
    // Установка флагов по умолчанию.
    _autoScroll = true;
    _tabKeyNavigate = false;
}

