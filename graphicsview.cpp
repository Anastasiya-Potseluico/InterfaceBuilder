#include "graphicsview.h"

/*
 * Конструктор графиксвью.
 * param [in] position Ссылка на позицию, которую должен занять виджет.
 * param [in] numberOfWidget Порядковый номер виджета.
 */
GraphicsView::GraphicsView(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(256,192)))
{
    // Установка флагов по умолчанию.
    _interactive = false;
    _verticalScrollPanel = as_needed;
    _horizontalScrollPanel = as_needed;
    _name = QString("GraphicsView").append(QString::number(numberOfWidget));
    // Добавление виджетов для настроек.
    addWidgetsForSettings();
}

/*
* Метод отрисовки графиксвью.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void GraphicsView::drawSelf(QGraphicsScene &scene)
{
    // Создаем представление графиксвью.
    GraphicsViewView * view = new GraphicsViewView(this);
    scene.addItem(view);
}

/*
* Метод установки настроек для графиксвью.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void GraphicsView::setSettings(QMap<QString, QString> &settings)
{
    // Устанавливаем общие настройки.
    AbstractWidget::setSettings(settings);
    QString temp;
    // Устанавливаем интерактивность.
    temp = settings.value("interactive");
    if(temp == "true")
        _interactive = true;
    else
        _interactive = false;
    // Устанавливаем необходимость вертикальной прокрутки.
    temp = settings.value("vertical");
    if(temp == "Always On")
    {
        _verticalScrollPanel = always_on;
    }
    else if(temp == "Always Off")
    {
        _verticalScrollPanel = always_off;
    }
    else if(temp == "As Needed")
    {
        _verticalScrollPanel = as_needed;
    }
    // Устанавливаем необходимость горизонтальной прокрутки.
    temp = settings.value("horizontal");
    if(temp == "Always On")
    {
        _horizontalScrollPanel = always_on;
    }
    else if(temp == "Always Off")
    {
        _horizontalScrollPanel = always_off;
    }
    else if(temp == "As Needed")
    {
        _horizontalScrollPanel = as_needed;
    }
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString GraphicsView::getClassname()
{
    return QString("GraphicsView");
}

/*
* Метод для добавления нужных виджетов настроек для графиксвью в диалоговом окне.
*/
void GraphicsView::addWidgetsForSettings()
{
    // Добавляем виджет для редактирования имени графиксвью.
    QLabel *labelName = new QLabel("Name Of Graphics View");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавляем виджеты для общих настроек.
    AbstractWidget::addWidgetsForSettings();
    // Добавляем флаг интерактивности.
    QCheckBox *interactive = new QCheckBox();
    interactive->setText("Interactive");
    interactive->setChecked(_interactive);
    interactive->setObjectName("interactive");
    // Добавляем комбобокс для настройка вертикальной прокрутки.
    QLabel *labelV= new QLabel("Vertical Scroll Bars");
    QComboBox *vertical = new QComboBox();
    vertical->setObjectName("vertical");
    vertical->addItem("Always On");
    vertical->addItem("Always Off");
    vertical->addItem("As Needed");
    switch (_verticalScrollPanel)
    {
    case always_on:
        vertical->setCurrentIndex(0);
        break;
    case always_off:
        vertical->setCurrentIndex(1);
        break;
    case as_needed:
        vertical->setCurrentIndex(2);
        break;
    }
    // Добавляем комбобокс для настройка горизонтальной прокрутки.
    QLabel *labelH= new QLabel("Horizontal Scroll Bars");
    QComboBox *horizontal = new QComboBox();
    horizontal->setObjectName("horizontal");
    horizontal->addItem("Always On");
    horizontal->addItem("Always Off");
    horizontal->addItem("As Needed");
    switch (_horizontalScrollPanel)
    {
    case always_on:
        horizontal->setCurrentIndex(0);
        break;
    case always_off:
        horizontal->setCurrentIndex(1);
        break;
    case as_needed:
        horizontal->setCurrentIndex(2);
        break;
    }

    _settings.append(interactive);
    _settings.append(labelV);
    _settings.append(vertical);
    _settings.append(labelH);
    _settings.append(horizontal);
}

/*
* Метод записи графиксвью в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void GraphicsView::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записываем имя виджета
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QGraphicsView");
    xmlWriter.writeAttribute("name",_name);
    // Записываем общие свойства.
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записываем флаг интерактивности.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","interactive");
    xmlWriter.writeTextElement("bool",_interactive ? "true":"false");
    xmlWriter.writeEndElement();
    // Записываем свойство вертикальной прокрутки.
    QString scrolls;
    switch (_verticalScrollPanel)
    {
        case as_needed:
        {
            scrolls = "Qt::ScrollBarAsNeeded";
            break;
        }
        case always_on:
        {
            scrolls = "Qt::ScrollBarAlwaysOn";
            break;
        }
        case always_off:
        {
            scrolls = "Qt::ScrollBarAlwaysOff";
            break;
        }
    }
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","verticalScrollBarPolicy");
    xmlWriter.writeTextElement("enum",scrolls);
    xmlWriter.writeEndElement();
    // Записываем свойство горизонтальной прокрутки.
    switch (_horizontalScrollPanel)
    {
        case as_needed:
        {
            scrolls = "Qt::ScrollBarAsNeeded";
            break;
        }
        case always_on:
        {
            scrolls = "Qt::ScrollBarAlwaysOn";
            break;
        }
        case always_off:
        {
            scrolls = "Qt::ScrollBarAlwaysOff";
            break;
        }
    }
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","horizontalScrollBarPolicy");
    xmlWriter.writeTextElement("enum",scrolls);
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}
