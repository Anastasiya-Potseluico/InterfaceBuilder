#include "lineedit.h"


LineEdit::LineEdit(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(113,20)))
{
    _name = QString("LineEdit_").append(QString::number(numberOfWidget));
    _text = QString("");
    _readOnly = false;
    addWidgetsForSettings();
}

void LineEdit::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLineEdit");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","readOnly");
    xmlWriter.writeTextElement("bool",_readOnly ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void LineEdit::drawSelf(QGraphicsScene &scene)
{
    LineEditView * view = new LineEditView(this);
    scene.addItem(view);
}

void LineEdit::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);

    QString temp;
    temp = settings.value("readOnly");
    if(temp == "true")
        _readOnly = true;
    else
        _readOnly = false;
    temp = settings.value("text");
    _text = temp;
    _settings.clear();
    addWidgetsForSettings();
}

QString LineEdit::getClassname()
{
    return QString("LineEdit");
}

void LineEdit::addWidgetsForSettings()
{
    _settings.clear();
    QLabel *labelName = new QLabel("Name Of Line Edit");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QLabel *labelText = new QLabel("Text Of Line Edit");
    QLineEdit *text = new QLineEdit();
    text->setObjectName("text");
    text->setText(_text);
    _settings.append(labelText);
    _settings.append(text);

    QCheckBox *readOnly = new QCheckBox();
    readOnly->setText("Interactive");
    readOnly->setChecked(_readOnly);
    readOnly->setObjectName("readOnly");

    _settings.append(readOnly);
}
