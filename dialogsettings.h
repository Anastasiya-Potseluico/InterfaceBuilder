#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QDateEdit>
#include <QComboBox>
#include <typeinfo>

#include "abstractwidget.h"


namespace Ui {
class DialogSettings;
}

class PushButton;
class DialogSettings : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogSettings(QWidget *parent = 0, AbstractWidget* widget = NULL, QMap<QString,QString> *map = NULL);
    ~DialogSettings();
    
private:
    QMap<QString, QString> *_map;
    AbstractWidget *_widget;
    Ui::DialogSettings *ui;
    void savePushButtonFields();
    void saveCalendarFields();
    void saveCheckBoxFields();
    void saveLineEditFields();
    void saveLabelFields();
    void saveGraphicsViewFields();
    void saveMainWindowFields();
    void saveListWidgetFields();
    void saveProgressBarFields();
    void saveSpinBoxFields();
    void saveButtonFields();
    void saveItemFields();
    void saveTableWidgetFields();
    void saveTreeWidgetFields();
    void saveComboBoxFields();


private slots:
    void saveWidgetFields();
};

#endif // DIALOGSETTINGS_H
