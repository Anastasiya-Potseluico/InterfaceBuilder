#include "label.h"


Label::Label(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(46,13)))
{
    _verticalAlignment = center_v;
    _horizontalAlignment = left;
    _name = QString("Label_").append(QString::number(numberOfWidget));
    _text = "Label";
    addWidgetsForSettings();
}

void Label::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLabel");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();

    QString alignment;
    switch (_verticalAlignment)
    {
        case top:
        {
            alignment = "Qt::AlignTop";
            break;
        }
        case center_v:
        {
            alignment = "Qt::AlignVCenter";
            break;
        }
        case bottom:
        {
            alignment = "Qt::AlignBottom";
            break;
        }
    }
    alignment.append("|");
    switch (_horizontalAlignment)
    {
        case left:
        {
            alignment.append("Qt::AlignLeft");
            break;
        }
        case center_h:
        {
            alignment.append("Qt::AlignHCenter");
            break;
        }
        case right:
        {
            alignment.append("Qt::AlignRight");
            break;
        }
        case justify:
        {
            alignment.append("Qt::AlignJustify");
            break;
        }
    }

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","alignment");
    xmlWriter.writeTextElement("set",alignment);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void Label::drawSelf(QGraphicsScene &scene)
{
    LabelView * view = new LabelView(this);
    scene.addItem(view);
}

void Label::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);

    QString temp;
    temp = settings.value("wordWrap");
    if(temp == "true")
        _wordWrap = true;
    else
        _wordWrap = false;
    temp = settings.value("vertical");
    if(temp == "Top")
    {
        _verticalAlignment = top;
    }
    else if(temp == "Center")
    {
        _verticalAlignment = center_v;
    }
    else if(temp == "Bottom")
    {
        _verticalAlignment = bottom;
    }

    temp = settings.value("horizontal");
    if(temp == "Left")
    {
        _horizontalAlignment = left;
    }
    else if(temp == "Center")
    {
        _horizontalAlignment = center_h;
    }
    else if(temp == "Right")
    {
        _horizontalAlignment = right;
    }
    else if(temp == "Justify")
    {
        _horizontalAlignment = justify;
    }
    temp = settings.value("text");
    _text = temp;
}

QString Label::getClassname()
{
    return QString("Label");
}

void Label::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Label");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QLabel *labelText = new QLabel("Text Of Label");
    QLineEdit *text = new QLineEdit();
    text->setObjectName("text");
    text->setText(_text);
    _settings.append(labelText);
    _settings.append(text);

    QCheckBox *wordWrap = new QCheckBox();
    wordWrap->setText("Interactive");
    wordWrap->setChecked(_wordWrap);
    wordWrap->setObjectName("wordWrap");

    QLabel *labelV= new QLabel("Vertical Alignment");
    QComboBox *vertical = new QComboBox();
    vertical->setObjectName("vertical");
    vertical->addItem("Top");
    vertical->addItem("Center");
    vertical->addItem("Bottom");
    switch (_verticalAlignment)
    {
    case top:
        vertical->setCurrentIndex(0);
        break;
    case center_v:
        vertical->setCurrentIndex(1);
        break;
    case bottom:
        vertical->setCurrentIndex(2);
        break;
    }

    QLabel *labelH= new QLabel("Horizontal Alignment");
    QComboBox *horizontal = new QComboBox();
    horizontal->setObjectName("horizontal");
    horizontal->addItem("Left");
    horizontal->addItem("Center");
    horizontal->addItem("Right");
    horizontal->addItem("Justify");
    switch (_horizontalAlignment)
    {
    case left:
        horizontal->setCurrentIndex(0);
        break;
    case center_h:
        horizontal->setCurrentIndex(1);
        break;
    case right:
        horizontal->setCurrentIndex(2);
        break;
    case justify:
        horizontal->setCurrentIndex(3);
        break;
    }

    _settings.append(wordWrap);
    _settings.append(labelV);
    _settings.append(vertical);
    _settings.append(labelH);
    _settings.append(horizontal);
}
