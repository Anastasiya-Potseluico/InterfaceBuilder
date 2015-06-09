#include "checkbox.h"

/*
* Конструктор чекбокса.
* param [in] position Ссылка на позицию, которую должен занять виджет.
* param [in] size Размер создаваемого виджета.
*/
CheckBox::CheckBox(QPoint &position, int numberOfWidget):AbstractButton(position,*(new QSize(70,17)))
{
    // Устанавливаем значения полей по умолчанию.
    _tristate = false;
    _text = "CheckBox";
    _name = QString("CheckBox_").append(QString::number(numberOfWidget));
    // Заполняем список виджетов для настроек.
    addWidgetsForSettings();
}

/*
* Метод записи чекбокса в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void CheckBox::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя виджета в файл.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QCheckBox");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие для кнопок свойства виджета.
    AbstractButton::writeSelfIntoFile(xmlWriter);
    // Записать свойство трех состояний.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","tristate");
    xmlWriter.writeTextElement("bool",_tristate ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

/*
* Метод отрисовки чекбокса.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void CheckBox::drawSelf(QGraphicsScene &scene)
{
    // Создать представление чекбокса.
    CheckBoxView * view = new CheckBoxView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для чекбокса.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void CheckBox::setSettings(QMap<QString, QString> &settings)
{
    // Установить настройки, общие для кнопок.
    AbstractButton::setSettings(settings);
    // Установить настройку трех состояний.
    QString tempString = settings.value("tristate");
    if(tempString == "true")
        this->_tristate = true;
    else
        this->_tristate = false;
    _settings.clear();
    // Передобавить виджеты для настроек.
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString CheckBox::getClassname()
{
    return QString("CheckBox");
}

/*
* Метод для добавления нужных виджетов настроек для чекбокса в диалоговом окне.
*/
void CheckBox::addWidgetsForSettings()
{
    // Добавить лейбл для изменения имени виджета.
    QLabel *labelName = new QLabel("Name Of CheckBox");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты, общие для кнопок.
    AbstractButton::addWidgetsForSettings();
    // Добавить флаг редактирования трех состояний чекбокса.
    QCheckBox *tristate = new QCheckBox();
    tristate->setText("Tri State");
    tristate->setChecked(_tristate);
    tristate->setObjectName("tristate");

    _settings.append(tristate);
}
