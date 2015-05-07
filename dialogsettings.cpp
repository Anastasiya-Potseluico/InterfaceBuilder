#include "dialogsettings.h"
#include "ui_dialogsettings.h"

DialogSettings::DialogSettings(QWidget *parent, AbstractWidget *widget, QMap<QString, QString> *map) :
    QDialog(parent),
    ui(new Ui::DialogSettings)
{
    _map = map;
    _widget = widget;
    QList<QWidget *> widgets = _widget->getSettings();
    ui->setupUi(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;
    for(int i = 0; i < widgets.size(); i++ )
    {
        mainLayout->addWidget(widgets.at(i));
    }
    QPushButton *ok = new QPushButton("Oê");
    ok->setDefault( false );
    ok->setAutoDefault( false ) ;
    mainLayout->addWidget(ok);
    QObject::connect(ok,SIGNAL(clicked()),(QObject*)this,SLOT(saveWidgetFields()));

    this->setLayout(mainLayout);
    prepareExtraValidation();
}

DialogSettings::~DialogSettings()
{
    delete ui;
}

void DialogSettings::savePushButtonFields()
{
    saveButtonFields();
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("defaultOn");
    if(tempBox->isChecked())
        _map->insert("defaultOn","true");
    else
        _map->insert("defaultOn","false");
    tempBox = this->findChild<QCheckBox*>("flat");
    if(tempBox->isChecked())
        _map->insert("flat","true");
    else
        _map->insert("flat","false");
}

void DialogSettings::saveCalendarFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("gridVisible");
    if(tempBox->isChecked())
        _map->insert("gridVisible","true");
    else
        _map->insert("gridVisible","false");
    QDateEdit *tempDate;
    tempDate = this->findChild<QDateEdit*>("maxDate");
    _map->insert("maxDate",tempDate->date().toString());
    tempDate = this->findChild<QDateEdit*>("minDate");
    _map->insert("minDate",tempDate->date().toString());
    tempDate = this->findChild<QDateEdit*>("selectedDate");
    _map->insert("selectedDate",tempDate->date().toString());
    QComboBox *tempCombo;
    tempCombo = this->findChild<QComboBox*>("weekDays");
    _map->insert("weekDays",tempCombo->currentText());
}

void DialogSettings::saveCheckBoxFields()
{
    saveButtonFields();
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("tristate");
    if(tempBox->isChecked())
        _map->insert("tristate","true");
    else
        _map->insert("tristate","false");
}

void DialogSettings::saveLineEditFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("readOnly");
    if(tempBox->isChecked())
        _map->insert("readOnly","true");
    else
        _map->insert("readOnly","false");

    QLineEdit* tempEdit = this->findChild<QLineEdit*>("text");
    _map->insert("text",tempEdit->text());
}

void DialogSettings::saveLabelFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("wordWrap");
    if(tempBox->isChecked())
        _map->insert("wordWrap","true");
    else
        _map->insert("wordWrap","false");

    QComboBox *tempCombo;
    tempCombo = this->findChild<QComboBox*>("vertical");
    _map->insert("vertical",tempCombo->currentText());

    tempCombo = this->findChild<QComboBox*>("horizontal");
    _map->insert("horizontal",tempCombo->currentText());

    QLineEdit* tempEdit = this->findChild<QLineEdit*>("text");
    _map->insert("text",tempEdit->text());
}

void DialogSettings::saveGraphicsViewFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("interactive");
    if(tempBox->isChecked())
        _map->insert("interactive","true");
    else
        _map->insert("interactive","false");

    QComboBox *tempCombo;
    tempCombo = this->findChild<QComboBox*>("vertical");
    _map->insert("vertical",tempCombo->currentText());

    tempCombo = this->findChild<QComboBox*>("horizontal");
    _map->insert("horizontal",tempCombo->currentText());
}

void DialogSettings::saveMainWindowFields()
{
    QLineEdit* tempEdit = this->findChild<QLineEdit*>("windowTitle");
    _map->insert("windowTitle",tempEdit->text());
}

void DialogSettings::saveListWidgetFields()
{
    saveItemFields();
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("wordWrap");
    if(tempBox->isChecked())
        _map->insert("wordWrap","true");
    else
        _map->insert("wordWrap","false");

    tempBox = this->findChild<QCheckBox*>("sortingEnabled");
    if(tempBox->isChecked())
        _map->insert("sortingEnabled","true");
    else
        _map->insert("sortingEnabled","false");

}

void DialogSettings::saveProgressBarFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("invertedAppearance");
    if(tempBox->isChecked())
        _map->insert("invertedAppearance","true");
    else
        _map->insert("invertedAppearance","false");

    tempBox = this->findChild<QCheckBox*>("textVisible");
    if(tempBox->isChecked())
        _map->insert("textVisible","true");
    else
        _map->insert("textVisible","false");

    QSpinBox* tempSpin;
    tempBox = this->findChild<QCheckBox*>("min");
    _map->insert("min",QString::number(tempSpin->value()));
    tempBox = this->findChild<QCheckBox*>("max");
    _map->insert("max",QString::number(tempSpin->value()));
    tempBox = this->findChild<QCheckBox*>("current");
    _map->insert("current",QString::number(tempSpin->value()));
}

void DialogSettings::saveSpinBoxFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("readOnly");
    if(tempBox->isChecked())
        _map->insert("readOnly","true");
    else
        _map->insert("readOnly","false");

    QSpinBox* tempSpin;
    tempBox = this->findChild<QCheckBox*>("min");
    _map->insert("min",QString::number(tempSpin->value()));
    tempBox = this->findChild<QCheckBox*>("max");
    _map->insert("max",QString::number(tempSpin->value()));
    tempBox = this->findChild<QCheckBox*>("current");
    _map->insert("current",QString::number(tempSpin->value()));
    tempBox = this->findChild<QCheckBox*>("step");
    _map->insert("step",QString::number(tempSpin->value()));
}

void DialogSettings::saveButtonFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("checkable");
    if(tempBox->isChecked())
        _map->insert("checkable","true");
    else
        _map->insert("checkable","false");

    tempBox = this->findChild<QCheckBox*>("isChecked");
    if(tempBox->isChecked())
        _map->insert("isChecked","true");
    else
        _map->insert("isChecked","false");

    QLineEdit* tempEdit = this->findChild<QLineEdit*>("text");
    _map->insert("text",tempEdit->text());
}

void DialogSettings::saveItemFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("autoscroll");
    if(tempBox->isChecked())
        _map->insert("autoscroll","true");
    else
        _map->insert("autoscroll","false");

    tempBox = this->findChild<QCheckBox*>("tabKeyNavigate");
    if(tempBox->isChecked())
        _map->insert("tabKeyNavigate","true");
    else
        _map->insert("tabKeyNavigate","false");
}

void DialogSettings::saveTableWidgetFields()
{
    saveItemFields();
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("showGrid");
    if(tempBox->isChecked())
        _map->insert("showGrid","true");
    else
        _map->insert("showGrid","false");

    QSpinBox* tempSpin;
    tempSpin = this->findChild<QSpinBox*>("col");
    _map->insert("col",QString::number(tempSpin->value()));
    tempSpin = this->findChild<QSpinBox*>("row");
    _map->insert("row",QString::number(tempSpin->value()));
}

void DialogSettings::saveTreeWidgetFields()
{
    saveItemFields();
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("headerVisible");
    if(tempBox->isChecked())
        _map->insert("headerVisible","true");
    else
        _map->insert("headerVisible","false");

    QSpinBox* tempSpin;
    tempSpin = this->findChild<QSpinBox*>("col");
    _map->insert("col",QString::number(tempSpin->value()));
}

void DialogSettings::saveComboBoxFields()
{
    QCheckBox* tempBox;
    tempBox = this->findChild<QCheckBox*>("isEditable");
    if(tempBox->isChecked())
        _map->insert("isEditable","true");
    else
        _map->insert("isEditable","false");

    QSpinBox* tempSpin;
    tempSpin = this->findChild<QSpinBox*>("currentIndex");
    _map->insert("currentIndex",QString::number(tempSpin->value()));

    QString tempString;

    QComboBox *tempCombo;
    tempCombo = this->findChild<QComboBox*>("items");
    for(int i = 0; i < tempCombo->count(); i++)
    {
        tempString.append(tempCombo->itemText(i));
        tempString.append("\n");
    }
    _map->insert("items",tempString);
}

void DialogSettings::prepareExtraValidation()
{
     QLineEdit* tempEdit = this->findChild<QLineEdit*>("name");
     QRegExp expr("^[a-zA-Z_][a-zA-Z0-9_]*$");
     tempEdit->setValidator(new QRegExpValidator(expr,this));
     QObject::connect(tempEdit,SIGNAL(editingFinished()),(QObject*)this,SLOT(makeExtraValidation()));

}

void DialogSettings::saveWidgetFields()
{
       QString widgetName = _widget->getClassname();
       QLineEdit* tempEdit = this->findChild<QLineEdit*>("name");
       _map->insert("name",tempEdit->text());
       QCheckBox* tempBox = this->findChild<QCheckBox*>("enabled");
       if(tempBox->isChecked())
           _map->insert("enabled","true");
       else
           _map->insert("enabled","false");

       if(widgetName == "PushButton")
       {
           savePushButtonFields();
       }
       else if (widgetName == "Calendar")
       {
           saveCalendarFields();
       }
       else if(widgetName == "CheckBox")
       {
            saveCheckBoxFields();
       }
       else if(widgetName == "ComboBox")
       {
            saveComboBoxFields();
       }
       else if(widgetName == "GraphicsView")
       {
           saveGraphicsViewFields();
       }
       else if(widgetName == "MainWindow")
       {
           saveMainWindowFields();
       }
       else if(widgetName == "Label")
       {
           saveLabelFields();
       }
       else if(widgetName == "LineEdit")
       {
           saveLineEditFields();
       }
       else if(widgetName == "ListWidget")
       {
           saveListWidgetFields();
       }
       else if(widgetName == "ProgressBar")
       {
           saveProgressBarFields();
       }
       else if(widgetName == "SpinBox")
       {
           saveSpinBoxFields();
       }
       else if(widgetName == "TableWidget")
       {
           saveTableWidgetFields();
       }
       else if(widgetName == "TreeWidget")
       {
           saveTreeWidgetFields();
       }
       else if(widgetName == "RadioButton")
       {
           saveButtonFields();
       }
       this->accept();
}

void DialogSettings::makeExtraValidation()
{

}

