#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>
#include <QFile>

/* ����� ������������ �������.
*/
class AbstractWidget
{
protected:
    QSize _size; // ������ ������.
    QPoint _position; // ������� ������� �� ������� ����.
    QString _name; // ��� �������.
    bool _enabled; // ��������� �������.

    //void drawSelf();
QString writeSelfIntoFile(QFile&file);
};

#endif // ABSTRACTWIDGET_H
