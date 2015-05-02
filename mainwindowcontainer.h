#ifndef MAINWINDOWCONTAINER_H
#define MAINWINDOWCONTAINER_H

#include "abstractwidget.h"
#include "mainwindowview.h"

class MainWindowContainer : public AbstractWidget
{
public:
    MainWindowContainer();
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);
    void setWidgets(QList<AbstractWidget*> widgets);
    void setSettings(QMap<QString, QString> &settings);
    QString getClassname();
    void addWidgetsForSettings();

private:
    QList <AbstractWidget*> _widgets; // Список виджетов, расположенных на главном окне.
    QString _windowTitle; // Название главного окна.
    QSize countWindowDimension(); // Метод расчета размера окна на основе имеющихся виджетов.

};

#endif // MAINWINDOWCONTAINER_H
