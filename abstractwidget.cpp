#include "abstractwidget.h"

/*
* ����������� ������������ �������.
* param [in] position ������ �� �������, ������� ������ ������ ������.
* param [in] size ������ ������������ �������.
*/
AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

/*
* ����� ���������� ������� ��������� �������� �������.
*/
void AbstractWidget::emitSettingsChangedSignal()
{
    emit this->settingsChanged();
}

/*
* ����� ��������� ������� �������.
* return ������� ������� �������.
*/
QPoint AbstractWidget::getPosition()
{
    QPoint returnedPoint(_position.x(),_position.y());
    return returnedPoint;
}

/*
* ����� ��������� ������� �������.
* return ������� ������ �������.
*/
QSize AbstractWidget::getSize()
{
    QSize returnedSize(_size.width(), _size.height());
    return returnedSize;
}

/*
* ����� ��������� �������� ��� �������� �������.
* return ������ �������� ��� �������� �������.
*/
QList<QWidget *> AbstractWidget::getSettings()
{
    return _settings;
}

/*
* ����� ��������� ����� �������.
* return ��� ������� � ���� ������.
*/
QString AbstractWidget::getName()
{
    return QString(_name);
}

/*
* ����� ��������� ������� �������.
* param [in] size ������ �� ����� ������ �������.
*/
void AbstractWidget::setSize(QSize &size)
{
    _size = size;
}

/*
* ����� ��������� ������� �������.
* param [in] size ������ �� ����� ������� �������.
*/
void AbstractWidget::setPosition(QPoint &position)
{
    _position = position;
}

void AbstractWidget::setGridPosition(int row, int col, int rowSpan, int colSpan)
{
    _rowSpan = rowSpan;
    _colSpan = colSpan;
    _gridCol = col;
    _gridRow = row;
}

void AbstractWidget::writeItemIntoFile(QXmlStreamWriter &xmlWriter)
{

}

int AbstractWidget::col()
{
    return _gridCol;
}

int AbstractWidget::row()
{
    return _gridRow;
}

int AbstractWidget::colSpan()
{
    return _colSpan;
}

int AbstractWidget::rowSpan()
{
    return _rowSpan;
}
