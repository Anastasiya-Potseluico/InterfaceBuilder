#include "spinbox.h"

SpinBox::SpinBox(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(42,22)))
{
    _name = QString("SpinBox_").append(QString::number(numberOfWidget));
    _readOnly = false;
    _maxValue = 99;
    _minValue = 0;
    _singleStep = 1;
    _value = 0;
    addWidgetsForSettings();
}

void SpinBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QSpinBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","readOnly");
    xmlWriter.writeTextElement("bool",_readOnly ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimum");
    xmlWriter.writeTextElement("number",QString::number(_minValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximum");
    xmlWriter.writeTextElement("number",QString::number(_maxValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","value");
    xmlWriter.writeTextElement("number",QString::number(_value));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","singleStep");
    xmlWriter.writeTextElement("number",QString::number(_singleStep));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void SpinBox::drawSelf(QGraphicsScene &scene)
{
    SpinBoxView * view = new SpinBoxView(this);
    scene.addItem(view);
}

void SpinBox::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);

    QString tempString = settings.value("readOnly");
    if(tempString == "true")
        this->_readOnly = true;
    else
        this->_readOnly = false;
    tempString = settings.value("max");
    this->_maxValue = tempString.toInt();
    tempString = settings.value("min");
    this->_minValue = tempString.toInt();
    tempString = settings.value("current");
    this->_value = tempString.toInt();
    tempString = settings.value("step");
    this->_singleStep = tempString.toInt();
    _settings.clear();
    addWidgetsForSettings();
}

QString SpinBox::getClassname()
{
    return QString("SpinBox");
}

void SpinBox::addWidgetsForSettings()
{
    _settings.clear();
    QLabel *labelName = new QLabel("Name Of Spin Box");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QCheckBox *readOnly = new QCheckBox();
    readOnly->setText("Read Only");
    readOnly->setChecked(_readOnly);
    readOnly->setObjectName("readOnly");

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

    QLabel *labelStep = new QLabel("Single Step");
    QSpinBox *step = new QSpinBox();
    step->setObjectName("current");
    step->setMaximum(1000);
    step->setMinimum(-1000);
    step->setValue(_singleStep);

    _settings.append(readOnly);

    _settings.append(labelMax);
    _settings.append(max);
    _settings.append(labelMin);
    _settings.append(min);
    _settings.append(labelCurr);
    _settings.append(current);
    _settings.append(labelStep);
    _settings.append(step);
}
