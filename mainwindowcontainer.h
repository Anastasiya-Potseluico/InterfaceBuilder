#ifndef MAINWINDOWCONTAINER_H
#define MAINWINDOWCONTAINER_H

#include "abstractwidget.h"

class MainWindowContainer : public AbstractWidget
{
public:
    MainWindowContainer(QList<AbstractWidget *> widgets);
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
    void drawSelf(QGraphicsScene &scene);

private:
    QList <AbstractWidget*> _widgets; // ������ ��������, ������������� �� ������� ����.
    QString _windowTitle; // �������� �������� ����.
    QSize countWindowDimension(); // ����� ������� ������� ���� �� ������ ��������� ��������.

};

#endif // MAINWINDOWCONTAINER_H
