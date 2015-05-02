#include "progressbar.h"

ProgressBar::ProgressBar(QPoint &position, int numberOfWidget) :AbstractWidget(position,*(new QSize(118,23)))
{
    _name = QString("ProgressBar_").append(QString::number(numberOfWidget));
    _textVisible = true;
    _value = 20;
    _invertedAppearance = false;
    _minValue = 0;
    _maxValue = 100;
    addWidgetsForSettings();
}

void ProgressBar::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QProgressBar");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","textVisible");
    xmlWriter.writeTextElement("bool",_textVisible ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","invertedAppearance");
    xmlWriter.writeTextElement("bool",_invertedAppearance ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","value");
    xmlWriter.writeTextElement("number",QString::number(_value));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximum");
    xmlWriter.writeTextElement("number",QString::number(_maxValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimum");
    xmlWriter.writeTextElement("number",QString::number(_minValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

}

void ProgressBar::drawSelf(QGraphicsScene &scene)
{
    ProgressBarView * view = new ProgressBarView(this);
    scene.addItem(view);
}

void ProgressBar::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);

    QString tempString = settings.value("textVisible");
    if(tempString == "true")
        this->_textVisible = true;
    else
        this->_textVisible = false;

    tempString = settings.value("invertedAppearance");
    if(tempString == "true")
        this->_invertedAppearance = true;
    else
        this->_invertedAppearance = false;

    tempString = settings.value("max");
    this->_maxValue = tempString.toInt();
    tempString = settings.value("min");
    this->_minValue = tempString.toInt();
    tempString = settings.value("current");
    this->_value = tempString.toInt();
}

QString ProgressBar::getClassname()
{
    return QString("ProgressBar");
}

void ProgressBar::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Progress Bar");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QCheckBox *textVisible = new QCheckBox();
    textVisible->setText("Text Visible");
    textVisible->setChecked(_textVisible);
    textVisible->setObjectName("textVisible");

    QCheckBox *invertedAppearance = new QCheckBox();
    invertedAppearance->setText("Inverted Text");
    invertedAppearance->setChecked(_invertedAppearance);
    invertedAppearance->setObjectName("invertedAppearance");

    QLabel *labelMax = new QLabel("Maximum Value");
    QSpinBox *max = new QSpinBox();
    max->setMaximum(1000);
    max->setMinimum(-1000);
    max->setObjectName("max");
    max->setValue(_maxValue);

    QLabel *labelMin = new QLabel("Minimum Value");
    QSpinBox *min = new QSpinBox();
    min->setMaximum(1000);
    min->setMinimum(-1000);
    min->setObjectName("min");
    min->setValue(_minValue);

    QLabel *labelCurr = new QLabel("Current Value");
    QSpinBox *current = new QSpinBox();
    current->setObjectName("current");
    current->setMaximum(1000);
    current->setMinimum(-1000);
    current->setValue(_value);

    _settings.append(textVisible);
    _settings.append(invertedAppearance);

    _settings.append(labelMax);
    _settings.append(max);
    _settings.append(labelMin);
    _settings.append(min);
    _settings.append(labelCurr);
    _settings.append(current);
}
