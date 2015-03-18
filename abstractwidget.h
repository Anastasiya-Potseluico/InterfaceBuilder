#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>
#include <QGraphicsScene>
#include <QFile>


/* Класс абстрактного виджета.
*/
class AbstractWidget
{
public:
    AbstractWidget(QPoint& position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    QPoint getPosition();
    QSize getSize();
    void setPosition(QPoint &position);
protected:
    QSize _size; // Размер видета.
    QPoint _position; // Позиция виджета на главное окне.
    QString _name; // Имя виджета.
    bool _enabled; // Видимость виджета.


    QString writeSelfIntoFile(QFile&file);

};

#endif // ABSTRACTWIDGET_H
