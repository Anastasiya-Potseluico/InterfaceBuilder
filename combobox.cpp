#include "combobox.h"

/*
* Конструктор комбобокса.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
ComboBox::ComboBox (QPoint&position, int numberOfWidget):AbstractWidget(position,*(new QSize(69,22)))
{
    // Установка полей по умолчанию.
    _name = QString("ComboBox_").append(QString::number(numberOfWidget));
    _currentIndex = -1;
    _isEditable = false;
    // Добавление виджетов для настройки диалогового окна.
    addWidgetsForSettings();
}

/*
* Метод записи комбобокса в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void ComboBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя комбобокса.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QComboBox");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие для виджета свойства.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать свойство редактируемости.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","editable");
    xmlWriter.writeTextElement("bool",_isEditable ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать текущий индекс.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","currentIndex");
    xmlWriter.writeTextElement("number", QString::number(_currentIndex));
    xmlWriter.writeEndElement();
    // Записать все айтемы виджета.
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

/*
* Метод отрисовки комбобокса.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void ComboBox::drawSelf(QGraphicsScene &scene)
{
    // Создать представление комбобокса.
    ComboBoxView * view = new ComboBoxView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для комбобокса.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void ComboBox::setSettings(QMap<QString, QString> &settings)
{
    // Установить общие для виджетов настройки.
    AbstractWidget::setSettings(settings);
    // Установить возможность редактирования виджета.
    QString tempString = settings.value("isEditable");
    if(tempString == "true")
        this->_isEditable = true;
    else
        this->_isEditable = false;
    // Установить текущий индекс.
    tempString = settings.value("currentIndex");
    this->_currentIndex = tempString.toInt();
    // Установить все айтемы.
    tempString = settings.value("items");
    QRegExp rx("(\\n)");
    _items = tempString.split(rx);
    _items.removeAt(_items.size()-1);
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString ComboBox::getClassname()
{
    return QString("ComboBox");
}

/*
* Метод для добавления нужных виджетов настроек для комбобокса в диалоговом окне.
*/
void ComboBox::addWidgetsForSettings()
{
    // Добавить лайнэдит для редактирования имени виджета.
    QLabel *labelName = new QLabel("Name Of Combo Box");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для редактирования общих свойств.
    AbstractWidget::addWidgetsForSettings();
    // Добавить флаг редактируемости.
    QCheckBox *isEditable = new QCheckBox();
    isEditable->setText("Is Editable");
    isEditable->setChecked(_isEditable);
    isEditable->setObjectName("isEditable");
    // Добавить комбобокс для айтемов.
    QLabel *labelItems= new QLabel("Items");
    QComboBox *items = new QComboBox();
    items->setEditable(true);
    items->setObjectName("items");
    for(int i = 0; i < _items.size(); i++)
        items->addItem(_items.at(i));
    // Добавить комбобокс для текущего индекса.
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
