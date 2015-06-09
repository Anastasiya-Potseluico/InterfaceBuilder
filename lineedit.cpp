#include "lineedit.h"

/*
 * Конструктор строки ввода.
 * param [in] position Ссылка на позицию, которую должен занять виджет.
 * param [in] numberOfWidget Порядковый номер виджета.
 */
LineEdit::LineEdit(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(113,20)))
{
    // Заполнение полей значениями по умолчанию.
    _name = QString("LineEdit_").append(QString::number(numberOfWidget));
    _text = QString("");
    _readOnly = false;
    addWidgetsForSettings();
}

/*
* Метод записи строки ввода в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void LineEdit::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя виджета.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLineEdit");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие свойства виджета.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать текст строки ввода.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();
    // Записать флаг только на чтение.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","readOnly");
    xmlWriter.writeTextElement("bool",_readOnly ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

/*
* Метод отрисовки строки ввода.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void LineEdit::drawSelf(QGraphicsScene &scene)
{
    // Создать представление строки ввода.
    LineEditView * view = new LineEditView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для строки ввода.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void LineEdit::setSettings(QMap<QString, QString> &settings)
{
    // Установить общие настройки.
    AbstractWidget::setSettings(settings);
    // Установить флаг только на чтение.
    QString temp;
    temp = settings.value("readOnly");
    if(temp == "true")
        _readOnly = true;
    else
        _readOnly = false;
    // Установить текст строки ввода.
    temp = settings.value("text");
    _text = temp;
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString LineEdit::getClassname()
{
    return QString("LineEdit");
}

/*
* Метод для добавления нужных виджетов настроек для строки ввода в диалоговом окне.
*/
void LineEdit::addWidgetsForSettings()
{
    // Добавить виджет для редактирования имени строки ввода.
    QLabel *labelName = new QLabel("Name Of Line Edit");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для общих настроек.
    AbstractWidget::addWidgetsForSettings();
    // Добавить виджет для редактирования текста строки ввода.
    QLabel *labelText = new QLabel("Text Of Line Edit");
    QLineEdit *text = new QLineEdit();
    text->setObjectName("text");
    text->setText(_text);
    _settings.append(labelText);
    _settings.append(text);
    // Добавить флаг только на чтение.
    QCheckBox *readOnly = new QCheckBox();
    readOnly->setText("Interactive");
    readOnly->setChecked(_readOnly);
    readOnly->setObjectName("readOnly");
    _settings.append(readOnly);
}
