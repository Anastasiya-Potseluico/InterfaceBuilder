#include "abstractbutton.h"

AbstractButton::AbstractButton(QPoint&position,QSize &size) : AbstractWidget(position, size)
{
    //AbstractWidget(position);
    _checkable = true;
    _isChecked = false;
    _text = QString("");
}

void AbstractButton::addWidgetsForSettings()
{

    AbstractWidget::addWidgetsForSettings();

    QLabel *textLabel = new QLabel("Text");
    QLineEdit *text = new QLineEdit();
    text->setObjectName("text");
    text->setText(_text);


    QCheckBox *checkable = new QCheckBox();
    checkable->setText("Button is checkable");
    checkable->setChecked(_checkable);
    checkable->setObjectName("checkable");


    QCheckBox *isChecked = new QCheckBox();
    isChecked->setText("Button is checked");
    isChecked->setChecked(_isChecked);
    isChecked->setObjectName("isChecked");
    if(_checkable)
    {
        isChecked->setEnabled(true);
    }
    else
    {
        isChecked->setEnabled(false);
    }

    _settings.append(textLabel);
    _settings.append(text);
    _settings.append(checkable);
    _settings.append(isChecked);
}

