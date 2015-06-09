#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "abstractbutton.h"
#include "checkboxview.h"

/*! \file checkbox.h
  *
  * \class CheckBox
  * \brief ����� ������� ��������.
  * \author �������� ���������
*/
class CheckBox : public AbstractButton
{
public:
    /*!
    *\brief ����������� ��������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    CheckBox(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ �������� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ��������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ��������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� �������� � ���������� ����.
    */
    void addWidgetsForSettings();

private:
    /*!\brief ����������� ���� ���������*/
    bool _tristate;
};

#endif // CHECKBOX_H
