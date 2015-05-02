#include "checkbox.h"

CheckBox::CheckBox(QPoint &position, int numberOfWidget):AbstractButton(position,*(new QSize(70,17)))
{
    _tristate = false;
    _text = "CheckBox";
    _name = QString("CheckBox_").append(QString::number(numberOfWidget));
    addWidgetsForSettings();
}

void CheckBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCheckBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","tristate");
    xmlWriter.writeTextElement("bool",_tristate ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void CheckBox::drawSelf(QGraphicsScene &scene)
{
    CheckBoxView * view = new CheckBoxView(this);
    scene.addItem(view);
}

void CheckBox::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    AbstractButton::setSettings(settings);
    QString tempString = settings.value("tristate");
    if(tempString == "true")
        this->_tristate = true;
    else
        this->_tristate = false;
}

QString CheckBox::getClassname()
{
    return QString("CheckBox");
}

void CheckBox::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of CheckBox");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractButton::addWidgetsForSettings();

    QCheckBox *tristate = new QCheckBox();
    tristate->setText("Tri State");
    tristate->setChecked(_tristate);
    tristate->setObjectName("tristate");

    _settings.append(tristate);
}
