#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "abstractwidget.h"
#include "lineeditview.h"

/*! \file lineedit.h
  *
  * \class LineEdit
  * \brief ����� ������� ������ �����.
  * \author ��������� ���������
*/
class LineEdit : public AbstractWidget
{
public:
    /*!
     *\brief ����������� ������ �����.
     *\param [in] position ������ �� �������, ������� ������ ������ ������.
     *\param [in] numberOfWidget ���������� ����� �������.
     */
    LineEdit(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ ������ ����� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ������ �����.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ������ �����.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ������ ����� � ���������� ����.
    */
    void addWidgetsForSettings();

private:
    /*!\brief ����� ������ �����*/
    QString _text;
    /*!\brief ���� ������ �� ������ ������ �����*/
    bool _readOnly;
};

#endif // LINEEDIT_H
