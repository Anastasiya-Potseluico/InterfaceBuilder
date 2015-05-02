#include "radiobutton.h"



RadioButton::RadioButton(QPoint&position, int numberOfWidget):AbstractButton(position, *(new QSize(82,17)))
{
    _name = QString("RadioButton_").append(QString::number(numberOfWidget));
    _text = "RadioButton";
    addWidgetsForSettings();
}

void RadioButton::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QRadioButton");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeEndElement();
}

void RadioButton::drawSelf(QGraphicsScene &scene)
{
    RadioButtonView * view = new RadioButtonView(this);
    scene.addItem(view);
}

void RadioButton::setSettings(QMap<QString, QString> &settings)
{
    AbstractButton::setSettings(settings);
}

void RadioButton::addWidgetsForSettings()
{

    QLabel *labelName = new QLabel("Name Of Radio Button");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractButton::addWidgetsForSettings();
}

QString RadioButton::getClassname()
{
    return QString("RadioButton");
}


