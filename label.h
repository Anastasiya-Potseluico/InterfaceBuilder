#ifndef LABEL_H
#define LABEL_H

#include "abstractwidget.h"
#include "labelview.h"

enum VERTICAL_ALIGNMENT {top, center_v, bottom};
enum HORIZONTAL_ALIGNMENT {Left, center_h, Right, justify};

/*! \file label.h
  *
  * \class Label
  * \brief ����� ������� ������.
  * \author ��������� ���������
*/
class Label : public AbstractWidget
{
public:
    /*!
     *\brief ����������� ������.
     *\param [in] position ������ �� �������, ������� ������ ������ ������.
     *\param [in] numberOfWidget ���������� ����� �������.
     */
    Label(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ ������ � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ������ � ���������� ����.
    */
    void addWidgetsForSettings();

private:
    /*!\brief ����� ������*/
    QString _text;
    /*!\brief ���� �������� ����*/
    bool _wordWrap;
    /*!\brief ������������ ������������*/
    VERTICAL_ALIGNMENT _verticalAlignment;
    /*!\brief �������������� ������������*/
    HORIZONTAL_ALIGNMENT _horizontalAlignment;
};

#endif // LABEL_H
