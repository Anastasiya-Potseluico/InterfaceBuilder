#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

/*! \file abstractwidget.h
  *
  * \class AbstractItemWidget
  * \brief ����� ������������ ������ ������.
  * \author �������� ���������
*/

class AbstractItemWidget : public AbstractWidget
{
public:
    /*!
    *\brief ����������� ������������ ������ ������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    AbstractItemWidget(QPoint &position, QSize &size);

    /*!
    *\brief ����� ��������� ������������ ������ ������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief ����� ��������� �������� ��� ������������ ������ ������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // ������������� ���������, ����� ��� ���� ��������.
        AbstractWidget::setSettings(settings);
        // ������������� ��������� ��������� �� ������ Tab.
        QString tempString = settings.value("tabKeyNavigate");
        if(tempString == "true")
            this->_tabKeyNavigate = true;
        else
            this->_tabKeyNavigate = false;
        // ������������� ��������� �������������.
        tempString = settings.value("autoScroll");
        if(tempString == "true")
            this->_autoScroll = true;
        else
            this->_autoScroll = false;
    }

    /*!
    *\brief ����� ������ ������������ ������ ������ � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        // ���������� ��� ����� �������� �������.
        AbstractWidget::writeSelfIntoFile(xmlWriter);

        // ���������� �������� ��������� �� ������ Tab.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","tabKeyNavigate");
        xmlWriter.writeTextElement("bool",_tabKeyNavigate ? "true":"false");
        xmlWriter.writeEndElement();

        // ���������� �������� �������������.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","autoScroll");
        xmlWriter.writeTextElement("bool",_autoScroll ? "true":"false");
        xmlWriter.writeEndElement();
    }

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ������������ ������ ������ � ���������� ����.
    */
    virtual void addWidgetsForSettings()
    {
        // ��������� ��� ����� ������� ��� ��������.
        AbstractWidget::addWidgetsForSettings();

        // ��������� ���� ��� ��������� ��������� �� ������ Tab.
        QCheckBox *tabKeyNavigate = new QCheckBox();
        tabKeyNavigate->setText("Tab Key Navigate");
        tabKeyNavigate->setChecked(_tabKeyNavigate);
        tabKeyNavigate->setObjectName("tabKeyNavigate");

        // ��������� ���� ��� ��������� �������������.
        QCheckBox *autoscroll = new QCheckBox();
        autoscroll->setText("Autoscroll");
        autoscroll->setChecked(_autoScroll);
        autoscroll->setObjectName("autoscroll");

        // ��������� ��� ��������� ������� � ������ ��������.
        _settings.append(tabKeyNavigate);
        _settings.append(autoscroll);
    }

protected:
    /*!\brief ���� ������������� ������������ ������ ������*/
    bool _autoScroll;
    /*!\brief ���� ����������� ��������� �� ������ � ������� ������ Tab*/
    bool _tabKeyNavigate;

};

#endif // ABSTRACTITEMWIDGET_H
