#include "abstractwidget.h"

/*
* Конструктор абстрактного виджета.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
AbstractWidget::AbstractWidget(QPoint &position, QSize &size)
{
    _position = position;
    _size = size;
    _enabled = true;
}

/*
* Метод испускания сигнала изменения настроек виджета.
*/
void AbstractWidget::emitSettingsChangedSignal()
{
    emit this->settingsChanged();
}

/*
* Метод получения позиции виджета.
* return Текущая позиция виджета.
*/
QPoint AbstractWidget::getPosition()
{
    QPoint returnedPoint(_position.x(),_position.y());
    return returnedPoint;
}

/*
* Метод получения размера виджета.
* return Текущий размер виджета.
*/
QSize AbstractWidget::getSize()
{
    QSize returnedSize(_size.width(), _size.height());
    return returnedSize;
}

/*
* Метод получения виджетов для настроек виджета.
* return Список виджетов для настроек виджета.
*/
QList<QWidget *> AbstractWidget::getSettings()
{
    return _settings;
}

/*
* Метод получения имени виджета.
* return Имя виджета в виде строки.
*/
QString AbstractWidget::getName()
{
    return QString(_name);
}

/*
* Метод изменения размера виджета.
* param [in] size Ссылка на новый размер виджета.
*/
void AbstractWidget::setSize(QSize &size)
{
    _size = size;
}

/*
* Метод изменения позиции виджета.
* param [in] size Ссылка на новую позицию виджета.
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
