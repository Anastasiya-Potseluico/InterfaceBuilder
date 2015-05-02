#include "pushbutton.h"

PushButton::PushButton(QPoint &position, int numberOfWidget) : AbstractButton(position,*(new QSize(75,23)))
{
    _defaultOn = false;
    _text = "PushButton";
    _flat = false;
    _checkable = false;
    _name = QString("PushButton_").append(QString::number(numberOfWidget));
    addWidgetsForSettings();
}

void PushButton::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QPushButton");
    xmlWriter.writeAttribute("name",_name);

    AbstractButton::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","default");
    xmlWriter.writeTextElement("bool",_defaultOn ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","flat");
    xmlWriter.writeTextElement("bool",_flat ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

}

void PushButton::drawSelf(QGraphicsScene &scene)
{
    PushButtonView * view = new PushButtonView(this);
    scene.addItem(view);
}

QString PushButton::getClassname()
{
    return QString("PushButton");
}

void PushButton::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Push Button");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractButton::addWidgetsForSettings();

    QCheckBox *defaultOn = new QCheckBox();
    defaultOn->setText("Default On");
    defaultOn->setChecked(_defaultOn);
    defaultOn->setObjectName("defaultOn");

    QCheckBox *flat = new QCheckBox();
    flat->setText("Flat Button");
    flat->setChecked(_flat);
    flat->setObjectName("flat");

    _settings.append(defaultOn);
    _settings.append(flat);
}

void PushButton::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    AbstractButton::setSettings(settings);
    QString tempString = settings.value("defaultOn");
    if(tempString == "true")
        this->_defaultOn = true;
    else
        this->_defaultOn = false;

    tempString = settings.value("flat");
    if(tempString == "true")
        this->_flat = true;
    else
        this->_flat = false;
}

