#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "abstractitemwidget.h"
#include "listwidgetview.h"

/*! \file listwidget.h
  *
  * \class ListWidget
  * \brief ����� ������� ������.
  * \author ��������� ���������
*/
class ListWidget : public AbstractItemWidget
{
public:
    /*!
     *\brief ����������� ������� ������.
     *\param [in] position ������ �� �������, ������� ������ ������ ������.
     *\param [in] numberOfWidget ���������� ����� �������.
     */
    ListWidget(QPoint &position, int numberOfWidget);

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
    /*!\brief ���� �������� ����*/
    bool _wordWrap;
    /*!\brief ���� ����������� ����������*/
    bool _sortingEnabled;
};

#endif // LISTWIDGET_H
