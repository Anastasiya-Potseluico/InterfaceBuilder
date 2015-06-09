#include "checkbox.h"

/*
* ����������� ��������.
* param [in] position ������ �� �������, ������� ������ ������ ������.
* param [in] size ������ ������������ �������.
*/
CheckBox::CheckBox(QPoint &position, int numberOfWidget):AbstractButton(position,*(new QSize(70,17)))
{
    // ������������� �������� ����� �� ���������.
    _tristate = false;
    _text = "CheckBox";
    _name = QString("CheckBox_").append(QString::number(numberOfWidget));
    // ��������� ������ �������� ��� ��������.
    addWidgetsForSettings();
}

/*
* ����� ������ �������� � ����.
* param [in] xmlWriter ������ �� ����� ������ � ���� � xml �������.
*/
void CheckBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // �������� ��� ������� � ����.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCheckBox");
    xmlWriter.writeAttribute("name",_name);
    // �������� ����� ��� ������ �������� �������.
    AbstractButton::writeSelfIntoFile(xmlWriter);
    // �������� �������� ���� ���������.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","tristate");
    xmlWriter.writeTextElement("bool",_tristate ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

/*
* ����� ��������� ��������.
* param [in] position ������ �� �����, �� ������� ������ ������������� ���������.
*/
void CheckBox::drawSelf(QGraphicsScene &scene)
{
    // ������� ������������� ��������.
    CheckBoxView * view = new CheckBoxView(this);
    scene.addItem(view);
}

/*
* ����� ��������� �������� ��� ��������.
* param [in] settings ������ �� ����� ������������ �������� � �� �������� � ��������� �������������.
*/
void CheckBox::setSettings(QMap<QString, QString> &settings)
{
    // ���������� ���������, ����� ��� ������.
    AbstractButton::setSettings(settings);
    // ���������� ��������� ���� ���������.
    QString tempString = settings.value("tristate");
    if(tempString == "true")
        this->_tristate = true;
    else
        this->_tristate = false;
    _settings.clear();
    // ������������ ������� ��� ��������.
    addWidgetsForSettings();
}

/*
* ����� ��������� ����� ������.
* return ��� ������ � ���� ������.
*/
QString CheckBox::getClassname()
{
    return QString("CheckBox");
}

/*
* ����� ��� ���������� ������ �������� �������� ��� �������� � ���������� ����.
*/
void CheckBox::addWidgetsForSettings()
{
    // �������� ����� ��� ��������� ����� �������.
    QLabel *labelName = new QLabel("Name Of CheckBox");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // �������� �������, ����� ��� ������.
    AbstractButton::addWidgetsForSettings();
    // �������� ���� �������������� ���� ��������� ��������.
    QCheckBox *tristate = new QCheckBox();
    tristate->setText("Tri State");
    tristate->setChecked(_tristate);
    tristate->setObjectName("tristate");

    _settings.append(tristate);
}
