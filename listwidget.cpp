#include "listwidget.h"

/*
 * Конструктор виджета списка.
 * param [in] position Ссылка на позицию, которую должен занять виджет.
 * param [in] numberOfWidget Порядковый номер виджета.
 */
ListWidget::ListWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    // Заполнить поля по умолчанию.
    _name = QString("ListWidget_").append(QString::number(numberOfWidget));
    _sortingEnabled = true;
    _wordWrap = true;
    addWidgetsForSettings();
}

/*
* Метод записи списка в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void ListWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя списка.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QListWidget");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие свойства для списка.
    AbstractItemWidget::writeSelfIntoFile(xmlWriter);
    // Записать свойство переноса слов.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать свойство возможности сортировки.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","sortingEnabled");
    xmlWriter.writeTextElement("bool",_sortingEnabled ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

/*
* Метод отрисовки списка.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void ListWidget::drawSelf(QGraphicsScene &scene)
{
    // Создать представление списка.
    ListWidgetView * view = new ListWidgetView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для списка.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void ListWidget::setSettings(QMap<QString, QString> &settings)
{
    // Установить стандартные настройки.
    AbstractItemWidget::setSettings(settings);
    // Установить флаг переноса слов.
    QString temp;
    temp = settings.value("wordWrap");
    if(temp == "true")
        _wordWrap = true;
    else
        _wordWrap = false;
    // Установить флаг возможности сортировки.
    temp = settings.value("sortingEnabled");
    if(temp == "true")
        _sortingEnabled = true;
    else
        _sortingEnabled = false;
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString ListWidget::getClassname()
{
    return QString("ListWidget");
}

/*
* Метод для добавления нужных виджетов настроек для списка в диалоговом окне.
*/
void ListWidget::addWidgetsForSettings()
{
    // Добавить виджет для редактирования имени списка.
    QLabel *labelName = new QLabel("Name Of List Widget");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для редактирования общих свойств.
    AbstractItemWidget::addWidgetsForSettings();
    // Добавить флаг переноса слов.
    QCheckBox *wordWrap = new QCheckBox();
    wordWrap->setText("Word Wrap");
    wordWrap->setChecked(_wordWrap);
    wordWrap->setObjectName("wordWrap");
    // Добавить флаг возможности сортировки.
    QCheckBox *sortingEnabled = new QCheckBox();
    sortingEnabled->setText("Sorting Enabled");
    sortingEnabled->setChecked(_sortingEnabled);
    sortingEnabled->setObjectName("sortingEnabled");
    _settings.append(wordWrap);
    _settings.append(sortingEnabled);
}

