#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>

/* Класс абстрактного виджета.
*/
class AbstractWidget
{
protected:
    QSize _size; // Размер видета.
    QPoint _position; // Позиция виджета на главное окне.
    QString _name; // Имя виджета.
};

#endif // ABSTRACTWIDGET_H
