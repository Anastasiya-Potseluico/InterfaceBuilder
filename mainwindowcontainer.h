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
    QList<AbstractWidget*> getWidgets();

private:
    QList <AbstractWidget*> _widgets; // ������ ��������, ������������� �� ������� ����.
    QString _windowTitle; // �������� �������� ����.
    QSize countWindowDimension(); // ����� ������� ������� ���� �� ������ ��������� ��������.
    void setWidgetsIntoGrig();
    int getCellsCount(int widgetAttribute, int cellDimension);
};

#endif // MAINWINDOWCONTAINER_H
