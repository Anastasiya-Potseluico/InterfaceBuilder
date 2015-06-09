#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "abstractwidget.h"
#include "comboboxview.h"

/*! \file combobox.h
  *
  * \class ComboBox
  * \brief ����� ������� ����������.
  * \author �������� ���������
*/
class ComboBox : public AbstractWidget
{
public:
    /*!
    *\brief ����������� ����������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    ComboBox(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ ���������� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ����������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ����������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ���������� � ���������� ����.
    */
    void addWidgetsForSettings();

private:
    /*!\brief ������ ����������*/
    QStringList _items;
    /*!\brief ���� ����������� �������������� �������*/
    bool _isEditable;
    /*!\brief ��������� ������ ����������*/
    int _currentIndex;

};

#endif // COMBOBOX_H
