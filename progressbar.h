#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "abstractwidget.h"
#include "progressbarview.h"

/*! \file progressbar.h
  *
  * \class ProgressBar
  * \brief ����� ������� ������ ���������.
  * \author ��������� ���������
*/
class ProgressBar : public AbstractWidget
{
public:
    /*!
     *\brief ����������� ������� ���������.
     *\param [in] position ������ �� �������, ������� ������ ������ ������.
     *\param [in] numberOfWidget ���������� ����� �������.
     */
    ProgressBar(QPoint &position, int numberOfWidget);

    /*!
    *\brief ����� ������ ��������-���� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief ����� ��������� ��������-����.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief ����� ��������� �������� ��� ��������-����.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    QString getClassname();

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ��������-���� � ���������� ����.
    */
    void addWidgetsForSettings();

private:
    /*!\brief ���� ��������� ������*/
    bool _textVisible;
    /*!\brief ������� �������� ���������*/
    int _value;
    /*!\brief ���� ��������� �����������*/
    bool _invertedAppearance;
    /*!\brief ����������� �������� ���������*/
    int _minValue;
    /*!\brief ������������ �������� ���������*/
    int _maxValue;
};

#endif // PROGRESSBAR_H
