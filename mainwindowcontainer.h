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
    QList <AbstractWidget*> _widgets; // Список виджетов, расположенных на главном окне.
    QString _windowTitle; // Название главного окна.
    QSize countWindowDimension(); // Метод расчета размера окна на основе имеющихся виджетов.

};

#endif // MAINWINDOWCONTAINER_H
