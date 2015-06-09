#include "progressbar.h"

/*
 * Конструктор виджета прогресса.
 * param [in] position Ссылка на позицию, которую должен занять виджет.
 * param [in] numberOfWidget Порядковый номер виджета.
 */
ProgressBar::ProgressBar(QPoint &position, int numberOfWidget) :AbstractWidget(position,*(new QSize(118,23)))
{
    // Установка параметров по умолчанию.
    _name = QString("ProgressBar_").append(QString::number(numberOfWidget));
    _textVisible = true;
    _value = 20;
    _invertedAppearance = false;
    _minValue = 0;
    _maxValue = 100;
    addWidgetsForSettings();
}

/*
* Метод записи прогресс-бара в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void ProgressBar::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать имя виджета в файл.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QProgressBar");
    xmlWriter.writeAttribute("name",_name);
    // Записать общие свойства виджета.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать свойство видимости текста.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","textVisible");
    xmlWriter.writeTextElement("bool",_textVisible ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать свойство обратного отображения текста.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","invertedAppearance");
    xmlWriter.writeTextElement("bool",_invertedAppearance ? "true":"false");
    xmlWriter.writeEndElement();
    // Записать текущее значние прогресса.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","value");
    xmlWriter.writeTextElement("number",QString::number(_value));
    xmlWriter.writeEndElement();
    // Записать максимальное значение прогресса.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","maximum");
    xmlWriter.writeTextElement("number",QString::number(_maxValue));
    xmlWriter.writeEndElement();
    // Записать минимальное значние прогресса.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","minimum");
    xmlWriter.writeTextElement("number",QString::number(_minValue));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

/*
* Метод отрисовки прогресс-бара.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void ProgressBar::drawSelf(QGraphicsScene &scene)
{
    // Создать представление прогресс-бара.
    ProgressBarView * view = new ProgressBarView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для прогресс-бара.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void ProgressBar::setSettings(QMap<QString, QString> &settings)
{
    // Установить общие настройки.
    AbstractWidget::setSettings(settings);
    // Установить настройку видимости текста.
    QString tempString = settings.value("textVisible");
    if(tempString == "true")
        this->_textVisible = true;
    else
        this->_textVisible = false;
    // Установить настройку обратного отображения текста.
    tempString = settings.value("invertedAppearance");
    if(tempString == "true")
        this->_invertedAppearance = true;
    else
        this->_invertedAppearance = false;
    // Установить максимальное значение прогресса.
    tempString = settings.value("max");
    this->_maxValue = tempString.toInt();
    // Установить минимальное значение прогресса.
    tempString = settings.value("min");
    this->_minValue = tempString.toInt();
    // Установить текущее значение прогресса.
    tempString = settings.value("current");
    this->_value = tempString.toInt();
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString ProgressBar::getClassname()
{
    return QString("ProgressBar");
}

/*
* Метод для добавления нужных виджетов настроек для прогресс-бара в диалоговом окне.
*/
void ProgressBar::addWidgetsForSettings()
{
    // Добавить виджет для редактирования имени прогресс-бара.
    QLabel *labelName = new QLabel("Name Of Progress Bar");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для редактирования общих свойств.
    AbstractWidget::addWidgetsForSettings();
    // Добавить флаг видимости текста.
    QCheckBox *textVisible = new QCheckBox();
    textVisible->setText("Text Visible");
    textVisible->setChecked(_textVisible);
    textVisible->setObjectName("textVisible");
    // Добавить флаг обратного отображения текста.
    QCheckBox *invertedAppearance = new QCheckBox();
    invertedAppearance->setText("Inverted Text");
    invertedAppearance->setChecked(_invertedAppearance);
    invertedAppearance->setObjectName("invertedAppearance");
    // Добавить спинбокс для максимального значения прогресса.
    QLabel *labelMax = new QLabel("Maximum Value");
    QSpinBox *max = new QSpinBox();
    max->setMaximum(1000);
    max->setMinimum(-1000);
    max->setObjectName("max");
    max->setValue(_maxValue);
    // Добавить спинбокс для минимального значения прогресса.
    QLabel *labelMin = new QLabel("Minimum Value");
    QSpinBox *min = new QSpinBox();
    min->setMaximum(1000);
    min->setMinimum(-1000);
    min->setObjectName("min");
    min->setValue(_minValue);
    // Добавить спинбокс для текущего значения прогресса.
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
