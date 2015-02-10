#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>

/* ����� ������������ �������.
*/
class AbstractWidget
{
protected:
    QSize _size; // ������ ������.
    QPoint _position; // ������� ������� �� ������� ����.
    QString _name; // ��� �������.
};

#endif // ABSTRACTWIDGET_H
