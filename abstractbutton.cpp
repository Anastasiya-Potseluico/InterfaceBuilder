#include "abstractbutton.h"

/*
* ����������� ����������� ������.
* param [in] position ������ �� �������, ������� ������ ������ ������.
* param [in] size ������ ������������ �������.
*/
AbstractButton::AbstractButton(QPoint&position, QSize &size) : AbstractWidget(position, size)
{
    // ����� �� ��������� ������������ ����� �������.
    _checkable = true;
    _isChecked = false;
    _text = QString("");
}

