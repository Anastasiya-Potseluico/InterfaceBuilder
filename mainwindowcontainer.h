#ifndef MAINWINDOWCONTAINER_H
#define MAINWINDOWCONTAINER_H

#include "abstractwidget.h"
#include "mainwindowview.h"

/*! \file mainwindowcontainer.h
  *
  * \class MainWindowContainer
  * \brief ����� ������� �������� ����.
  * \author ��������� ���������
*/
class MainWindowContainer : public AbstractWidget
{
public:
    /*!
     *\brief ����������� ������� �������� ����.
     */
    MainWindowContainer();

    /*!
    *\brief ����� ������ �������� ���� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� �������� ����.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ���������� ������ �������� �� ������� ����.
    *\param [in] widgets ������ �� ������ ��������.
    */
    void setWidgets(QList<AbstractWidget*> &widgets);

    /*!
    *\brief ����� ��������� �������� ��� �������� ����.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� �������� ���� � ���������� ����.
    */
    void addWidgetsForSettings();

    /*!
    *\brief ����� ��������� ������� ��� �������� ����.
    *\param [in] layout �������� ����� ��������� ����������.
    */
    void setAutoLayout(bool layout);

    /*!
    *\brief ����� ��������� �������� �� ������� ����.
    *\return ������ �������� �������� ����.
    */
    QList<AbstractWidget*> getWidgets();

private:
    /*!\brief ������ ��������, ������������� �� ������� ����*/
    QList <AbstractWidget*> _widgets;
    /*!\brief ��������� �������� ����*/
    QString _windowTitle;
    /*!\brief ���� ��������������*/
    bool _autoLayout;

    /*!
    *\brief ����� ��������� ������� �������� ���� � ����������� �� ��������.
    *\return ������������ ������ �������� ����.
    */
    QSize countWindowDimension();

    /*!
    *\brief ����� ��� ������������� �������� �� ����� ����������.
    */
    void setWidgetsIntoGrig();

    /*!
    *\brief ����� ��������� ������ ������ ����� �� ������ �� ����������.
    *\param [in] widgetAttribute ���� �� ���������, ������ ��� ������ �������.
    *\param [in] cellDimension ������ ��� ������ ������ �����.
    *\return ����� ������ ����� �� ��������� ��� �����������.
    */
    int getCellsCount(int widgetAttribute, int cellDimension);
};

#endif // MAINWINDOWCONTAINER_H
