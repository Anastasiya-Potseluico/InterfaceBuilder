#include "combobox.h"
#include "abstractbutton.h"

ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractWidget(position,*(new QSize(69,22)))
{
    _name = QString("ComboBox_").append(QString::number(numberOfWidget));
    _currentIndex = -1;
    _isEditable = false;
    addWidgetsForSettings();
}

void ComboBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QComboBox");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","editable");
    xmlWriter.writeTextElement("bool",_isEditable ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","currentIndex");
    xmlWriter.writeTextElement("number", QString::number(_currentIndex));
    xmlWriter.writeEndElement();

    if(_items.size()) {
        int i;
        for(i = 0; i < _items.size(); i++)
        {
            xmlWriter.writeStartElement("item");

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","text");
            xmlWriter.writeTextElement("string", _items.at(i));
            xmlWriter.writeEndElement();

            xmlWriter.writeEndElement();
        }
    }

    xmlWriter.writeEndElement();
}

void ComboBox::drawSelf(QGraphicsScene &scene)
{
    ComboBoxView * view = new ComboBoxView(this);
    scene.addItem(view);
}

void ComboBox::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    QString tempString = settings.value("isEditable");
    if(tempString == "true")
        this->_isEditable = true;
    else
        this->_isEditable = false;

    tempString = settings.value("currentIndex");
    this->_currentIndex = tempString.toInt();

    tempString = settings.value("items");
    QRegExp rx("(\\n)");
    _items = tempString.split(rx);
    _items.removeAt(_items.size()-1);
    _settings.clear();
    addWidgetsForSettings();

}

QString ComboBox::getClassname()
{
    return QString("ComboBox");
}

void ComboBox::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Combo Box");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QCheckBox *isEditable = new QCheckBox();
    isEditable->setText("Is Editable");
    isEditable->setChecked(_isEditable);
    isEditable->setObjectName("isEditable");

    QLabel *labelItems= new QLabel("Items");
    QComboBox *items = new QComboBox();
    items->setEditable(true);
    items->setObjectName("items");
    for(int i = 0; i < _items.size(); i++)
        items->addItem(_items.at(i));

    QLabel *labelIndex = new QLabel("Current Index");
    QSpinBox *index = new QSpinBox();
    index->setObjectName("currentIndex");
    index->setMaximum(100);
    index->setMinimum(-1);
    index->setValue(_currentIndex);

    _settings.append(isEditable);
    _settings.append(labelItems);
    _settings.append(items);
    _settings.append(labelIndex);
    _settings.append(index);
}
