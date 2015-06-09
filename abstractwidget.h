#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QCheckBox>
#include <QFile>
#include <QGraphicsScene>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QObject>
#include <QPoint>
#include <QSize>
#include <QSpinBox>
#include <QString>
#include <QXmlStreamWriter>

/*! \file abstractwidget.h
  *
  * \class AbstractWidget
  * \brief ����� ������������ �������.
  * \author �������� ���������
*/

class AbstractWidget : public QObject
{

    Q_OBJECT

public:

    /*!
    *\brief ����������� ������������ �������.
    *\param [in] position ������ �� �������, ������� ������ ������ ������.
    *\param [in] size ������ ������������ �������.
    */
    AbstractWidget(QPoint& position, QSize &size);

    /*!
    *\brief ����� ���������� ������� ��������� �������� �������.
    */
    void emitSettingsChangedSignal();

    /*!
    *\brief ����� ��������� ������������ �������.
    *\param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief ����� ��������� ����� ������.
    *\return ��� ������ � ���� ������.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief ����� ��������� �������� ��� ������������ �������.
    *\param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // ������������� ��������� ����� �������.
        QString tempString = settings.value("name");
        this->_name = tempString;
        // ������������� ��������� ��������� �������.
        tempString = settings.value("enabled");
        if(tempString == "true")
            this->_enabled = true;
        else
            this->_enabled = false;
    }

    /*!
    *\brief ����� ��������� ������� �������.
    *\return ������� ������� �������.
    */
    QPoint getPosition();

    /*!
    *\brief ����� ��������� ������� �������.
    *\return ������� ������ �������.
    */
    QSize getSize();

    /*!
    *\brief ����� ��������� �������� ��� �������� �������.
    *\return ������ �������� ��� �������� �������.
    */
    QList<QWidget*> getSettings();

    /*!
    *\brief ����� ��������� ����� �������.
    *\return ��� ������� � ���� ������.
    */
    QString getName();

    /*!
    *\brief ����� ��������� ������� �������.
    *\param [in] size ������ �� ����� ������ �������.
    */
    void setSize(QSize &size);

    /*!
    *\brief ����� ��������� ������� �������.
    *\param [in] size ������ �� ����� ������� �������.
    */
    void setPosition(QPoint &position);

    /*!
    *\brief ����� ������ ������������ ������� � ����.
    *\param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
            // ���������� ��� �������.
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","geometry");
            // ���������� ������ �������.
            xmlWriter.writeStartElement("rect");
            xmlWriter.writeTextElement("x",QString::number(this->_position.x()));
            xmlWriter.writeTextElement("y",QString::number(this->_position.y()));
            xmlWriter.writeTextElement("width",QString::number(this->_size.width()));
            xmlWriter.writeTextElement("height",QString::number(this->_size.height()));
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
            // ���������� ��������� �������.
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","enabled");
            xmlWriter.writeTextElement("bool",_enabled ? "true":"false");
            xmlWriter.writeEndElement();
    }

    /*!
    *\brief ����� ��� ���������� ������ �������� �������� ��� ����������� ������ � ���������� ����.
    */
    virtual  void addWidgetsForSettings()
    {
        QCheckBox *enabled = new QCheckBox();
        enabled->setText("Widget is enabled");
        enabled->setChecked(_enabled);
        enabled->setObjectName("enabled");
        _settings.append(enabled);
    }

    void setGridPosition(int row, int col, int rowSpan, int colSpan);

    void writeItemIntoFile(QXmlStreamWriter &xmlWriter);

    int col();
    int row();
    int colSpan();
    int rowSpan();

signals:
    /*!
    *\brief ������, ������������� ��� ��������� �������� �������.
    */
    void settingsChanged();

protected:
    /*!\brief ������ �������*/
    QSize _size;
    /*!\brief ������� �������*/
    QPoint _position;
    /*!\brief ��� �������*/
    QString _name;
    /*!\brief ��������� �������*/
    bool _enabled;
    /*!\brief ������ �������� ��� �������*/
    QList<QWidget*> _settings;

    //???!!!!
    int _gridCol; // ��������� ������� � ����� ������� (�������).
    int _gridRow; // ��������� ������� � ����� ������� (������).
    int _colSpan; // ������� ������� �������� ������ � �������.
    int _rowSpan; // ������� ����� �������� ������ � �������.
};

#endif // ABSTRACTWIDGET_H
