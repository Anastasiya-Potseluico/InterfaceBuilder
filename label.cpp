#include "label.h"

/*
 * Конструктор лейбла.
 * param [in] position Ссылка на позицию, которую должен занять виджет.
 * param [in] numberOfWidget Порядковый номер виджета.
 */
Label::Label(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(46,13)))
{
    // УСтанавливаем значение полей по умолчанию
    _verticalAlignment = center_v;
    _horizontalAlignment = Left;
    _name = QString("Label_").append(QString::number(numberOfWidget));
    _text = "Label";
    addWidgetsForSettings();
}

/*
* Метод записи лейбла в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void Label::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя виджета.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QLabel");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие свойства виджета.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать свойство переноса слов.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать текст лейбла.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","text");
    xmlWriter.writeTextElement("string",_text);
    xmlWriter.writeEndElement();
    // Записать вертикальное выравнивание.
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
    // Записать горизонтальное выравнивание.
    switch (_horizontalAlignment)
    {
        case Left:
        {
            alignment.append("Qt::AlignLeft");
            break;
        }
        case center_h:
        {
            alignment.append("Qt::AlignHCenter");
            break;
        }
        case Right:
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

/*
* Метод отрисовки лейбла.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void Label::drawSelf(QGraphicsScene &scene)
{
    // Создаем представление лейбла.
    LabelView * view = new LabelView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для лейбла.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void Label::setSettings(QMap<QString, QString> &settings)
{
    // Установить общие настройки.
    AbstractWidget::setSettings(settings);
    // Установить настройку переноса слов.
    QString temp;
    temp = settings.value("wordWrap");
    if(temp == "true")
        _wordWrap = true;
    else
        _wordWrap = false;
    // Установить вертикальное выравнивание.
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
    // Установить горизонтальное выравнивание.
    temp = settings.value("horizontal");
    if(temp == "Left")
    {
        _horizontalAlignment = Left;
    }
    else if(temp == "Center")
    {
        _horizontalAlignment = center_h;
    }
    else if(temp == "Right")
    {
        _horizontalAlignment = Right;
    }
    else if(temp == "Justify")
    {
        _horizontalAlignment = justify;
    }
    temp = settings.value("text");
    _text = temp;
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString Label::getClassname()
{
    return QString("Label");
}

/*
* Метод для добавления нужных виджетов настроек для лейбла в диалоговом окне.
*/
void Label::addWidgetsForSettings()
{
    // Добавить поле редактирования имени виджета.
    QLabel *labelName = new QLabel("Name Of Label");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для стандартных настроек.
    AbstractWidget::addWidgetsForSettings();
    // Добавить виджет для редактирования текста лейбла.
    QLabel *labelText = new QLabel("Text Of Label");
    QLineEdit *text = new QLineEdit();
    text->setObjectName("text");
    text->setText(_text);
    _settings.append(labelText);
    _settings.append(text);
    // Добавить флаг для переноса слов.
    QCheckBox *wordWrap = new QCheckBox();
    wordWrap->setText("Interactive");
    wordWrap->setChecked(_wordWrap);
    wordWrap->setObjectName("wordWrap");
    // Добавить комбобокс для редактирования вертикального выравнивания.
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
    // Добавить комбобокс для редактирования горизонтального выравнивания.
    QLabel *labelH= new QLabel("Horizontal Alignment");
    QComboBox *horizontal = new QComboBox();
    horizontal->setObjectName("horizontal");
    horizontal->addItem("Left");
    horizontal->addItem("Center");
    horizontal->addItem("Right");
    horizontal->addItem("Justify");
    switch (_horizontalAlignment)
    {
    case Left:
        horizontal->setCurrentIndex(0);
        break;
    case center_h:
        horizontal->setCurrentIndex(1);
        break;
    case Right:
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
