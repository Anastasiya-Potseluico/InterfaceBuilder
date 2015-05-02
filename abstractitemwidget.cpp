#include "abstractitemwidget.h"

AbstractItemWidget::AbstractItemWidget(QPoint &position, QSize &size) : AbstractWidget(position, size)
{
    _autoScroll = true;
    _tabKeyNavigate = false;
}

void AbstractItemWidget::addWidgetsForSettings()
{
    AbstractWidget::addWidgetsForSettings();

    QCheckBox *tabKeyNavigate = new QCheckBox();
    tabKeyNavigate->setText("Tab Key Navigate");
    tabKeyNavigate->setChecked(_tabKeyNavigate);
    tabKeyNavigate->setObjectName("tabKeyNavigate");


    QCheckBox *autoscroll = new QCheckBox();
    autoscroll->setText("Autoscroll");
    autoscroll->setChecked(_autoScroll);
    autoscroll->setObjectName("autoscroll");

    _settings.append(tabKeyNavigate);
    _settings.append(autoscroll);
}
