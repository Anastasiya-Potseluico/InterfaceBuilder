#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>
#include <QGraphicsScene>
#include <QXmlStreamWriter>


/* ����� ������������ �������.
*/
class AbstractWidget
{
public:
    AbstractWidget(QPoint& position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    QPoint getPosition();
    QSize getSize();
    void setPosition(QPoint &position);
    QString writeSelfIntoFile(QXmlStreamWriter &xmlWriter);
protected:
    QSize _size; // ������ ������.
    QPoint _position; // ������� ������� �� ������� ����.
    QString _name; // ��� �������.
    bool _enabled; // ��������� �������.

};

#endif // ABSTRACTWIDGET_H
