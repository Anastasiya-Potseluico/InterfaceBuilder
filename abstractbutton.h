#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QImage>

#include "abstractwidget.h"

/*! \file abstractbutton.h
  *
  * \class AbstractButton
  * \brief ����� ����������� ������.
  * \author �������� ���������
*/

class AbstractButton : public AbstractWidget
{
public:
    /*!
    *\brief ����������� ����������� ������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    AbstractButton(QPoint &position, QSize &size);

    /*!
    *\brief ����� ��������� ����������� ������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief ����� ��������� �������� ��� ����������� ������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // ������������� ���������, ����� ��� ���� ��������.
        AbstractWidget::setSettings(settings);
        // ���� ��������� ������ ������
        QString tempString = settings.value("text");
        _text = tempString;
        // ���� ��������� ��� ����������� ������� ������.
        tempString = settings.value("checkable");
        if(tempString == "true")
            _checkable = true;
        else
            _checkable = false;
        // ���� ��������� ��� ����� ��������� ������.
        tempString = settings.value("isChecked");
        if(tempString == "true")
            _isChecked = true;
        else
            _isChecked = false;
    }

    /*!
    *\brief ����� ������ ����������� ������ � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        // ���������� � ���� ������� ��������, ����� ��� ���� ��������.
        AbstractWidget::writeSelfIntoFile(xmlWriter);
        // ���������� ����� ������.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","text");
        xmlWriter.writeTextElement("string",_text);
        xmlWriter.writeEndElement();
        // ���������� ���� ����������� ������� ������.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","checkable");
        xmlWriter.writeTextElement("bool",_checkable ? "true":"false");
        xmlWriter.writeEndElement();
        // ���� ������ ����� ������, ���������� ��������� ��������� ������.
        if(_checkable)
        {
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","checked");
            xmlWriter.writeTextElement("bool",_isChecked ? "true":"false");
            xmlWriter.writeEndElement();
        }
    }

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ����������� ������ � ���������� ����.
    */
    virtual void addWidgetsForSettings()
    {
        // ��������� ������� ��� ����� ��������.
        AbstractWidget::addWidgetsForSettings();
        // ��������� ���� ��� ����� ������ ������.
        QLabel *textLabel = new QLabel("Text");
        QLineEdit *text = new QLineEdit();
        text->setObjectName("text");
        text->setText(_text);
        // ��������� ������� ��� �������������� ����������� ������� ������.
        QCheckBox *checkable = new QCheckBox();
        checkable->setText("Button is checkable");
        checkable->setChecked(_checkable);
        checkable->setObjectName("checkable");
        // ��������� ������� ��� �������������� ��������� ��������� ������.
        QCheckBox *isChecked = new QCheckBox();
        isChecked->setText("Button is checked");
        isChecked->setChecked(_isChecked);
        isChecked->setObjectName("isChecked");
        if(_checkable)
        {
            isChecked->setEnabled(true);
        }
        else
        {
            isChecked->setEnabled(false);
        }
        // ��� ��������� ������� ��������� � ������ �������� ��� ��������.
        _settings.append(textLabel);
        _settings.append(text);
        _settings.append(checkable);
        _settings.append(isChecked);
    }

protected:
    /*!\brief ���� ����������� ������ ���� �������*/
    bool _checkable;
    /*!\brief ���� ��������� ������*/
    bool _isChecked;
    /*!\brief �����, �������������� ������ ������*/
    QString _text;
};

#endif // ABSTRACTBUTTON_H
