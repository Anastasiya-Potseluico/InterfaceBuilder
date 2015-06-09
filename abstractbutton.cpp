#include "abstractbutton.h"

/*
* Конструктор абстрактной кнопки.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
AbstractButton::AbstractButton(QPoint&position, QSize &size) : AbstractWidget(position, size)
{
    // Флаги по умолчанию выставляются таким образом.
    _checkable = true;
    _isChecked = false;
    _text = QString("");
}

