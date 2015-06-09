#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "graphicsviewview.h"

enum NEEDED_SCROLL_PANELS {always_on, always_off, as_needed};

/*! \file graphicsview.h
  *
  * \class GraphicsView
  * \brief ����� ������� ������������ �����������.
  * \author ��������� ���������
*/
class GraphicsView : public AbstractWidget
{
public:
   /*!
    *\brief ����������� ����������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] numberOfWidget ���������� ����� �������.
    */
    GraphicsView(QPoint &position, int numberOfWidget);

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
    /*!\brief ���� ���������������*/
    bool _interactive;
    /*!\brief ������������� ������������ ���������*/
    NEEDED_SCROLL_PANELS _verticalScrollPanel;
    /*!\brief ������������� �������������� ���������*/
    NEEDED_SCROLL_PANELS _horizontalScrollPanel;
};

#endif // GRAPHICSVIEW_H
