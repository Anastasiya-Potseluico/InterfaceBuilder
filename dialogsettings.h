#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QCheckBox>
#include <QDateEdit>
#include <QComboBox>
#include <QMessageBox>
#include <typeinfo>

#include "abstractwidgetview.h"


namespace Ui {
class DialogSettings;
}

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
    void prepareExtraValidation();
    void makeConnections();


private slots:
    void saveWidgetFields();
    void makeExtraValidation();
};

#endif // DIALOGSETTINGS_H
