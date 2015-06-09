#include "mainwindowcontainer.h"

/*
 * Конструктор виджета главного окна.
 */
MainWindowContainer::MainWindowContainer():AbstractWidget(*(new QPoint(0,0)),*(new QSize(256,192)))
{
    // Заполнение полей по умолчанию.
    _windowTitle = "MainWindow";
    _name = "MainWindow";
    _autoLayout = false;
    addWidgetsForSettings();
}

/*
* Метод записи главного окна в файл.
* param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
*/
void MainWindowContainer::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    // Записать название главного окна.
    xmlWriter.writeTextElement("class",_name);
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QMainWindow");
    xmlWriter.writeAttribute("name",_name);
    AbstractWidget::writeSelfIntoFile(xmlWriter);
    // Записать заголовок окна.
    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","windowTitle");
    xmlWriter.writeTextElement("string",_windowTitle);
    xmlWriter.writeEndElement();
    // Записать центральный виджет.
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QWidget");
    xmlWriter.writeAttribute("name","centralWidget");
    // Если есть компоновка, предусмотреть ее запись.
    if(_autoLayout)
    {
        xmlWriter.writeStartElement("layout");
        xmlWriter.writeAttribute("class","QGridLayout");
        xmlWriter.writeAttribute("name","gridLayout");
        setWidgetsIntoGrig();
    }
    // Записать каждый виджет в файл.
    int i;
    for (i = 0; i < _widgets.size(); i++) {

        if(_autoLayout)
        {
            xmlWriter.writeStartElement("item");
            xmlWriter.writeAttribute("row",QString::number(_widgets.at(i)->row()));
            xmlWriter.writeAttribute("column",QString::number(_widgets.at(i)->col()));
            xmlWriter.writeAttribute("rowspan",QString::number(_widgets.at(i)->rowSpan()));
            xmlWriter.writeAttribute("colspan",QString::number(_widgets.at(i)->colSpan()));
        }
        _widgets[i]->writeSelfIntoFile(xmlWriter);
        if(_autoLayout)
        {
            xmlWriter.writeEndElement();

        }
    }
    // Закрыть тег компоновки, если она была выставлена.
    if(_autoLayout)
    {
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
    xmlWriter.writeEndElement();
}

/*
* Метод отрисовки главного окна.
* param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
*/
void MainWindowContainer::drawSelf(QGraphicsScene &scene)
{
    // Создать представление главного окна.
    MainWindowView * mainWindow= new MainWindowView(this);
    scene.addItem(mainWindow);
    // Отрисовать каждый виж, принадлежащий главному окну.
    int i;
    for (i = 0; i < _widgets.size(); i++)
    {
        _widgets[i]->drawSelf(scene);
    }
}

/*
* Метод добавления списка виджетов на главное окно.
* param [in] position Ссылка на список виджетов.
*/
void MainWindowContainer::setWidgets(QList<AbstractWidget *> &widgets)
{
    if(widgets.size()!=0)
    {
        _widgets = widgets;
        // Посчитать размер главного окна.
        _size = countWindowDimension();
    }
}

/*
* Метод установки настроек для главного окна.
* param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
*/
void MainWindowContainer::setSettings(QMap<QString, QString> &settings)
{
    // Установить общие настройки.
    AbstractWidget::setSettings(settings);
    // Установить заголовок главного окна.
    QString tempString = settings.value("windowTitle");
    _windowTitle = tempString;
    _settings.clear();
    addWidgetsForSettings();
}

/*
* Метод получения имени класса.
* return Имя класса в виде строки.
*/
QString MainWindowContainer::getClassname()
{
    return QString("MainWindow");
}

/*
* Метод для добавления нужных виджетов настроек для главного окна в диалоговом окне.
*/
void MainWindowContainer::addWidgetsForSettings()
{
    // Добавить виджет для редактирования имени главного окна.
    QLabel *labelName = new QLabel("Name Of Main Window");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);
    // Добавить виджеты для редактирования общих свойств.
    AbstractWidget::addWidgetsForSettings();
    // Добавить виджет для изменения заголовка окна.
    QLabel *labelTitle = new QLabel("Window Title");
    QLineEdit *title = new QLineEdit();
    title->setObjectName("windowTitle");
    title->setText(_windowTitle);
    _settings.append(labelName);
    _settings.append(name);
    _settings.append(labelTitle);
    _settings.append(title);
}

/*
* Метод установки лейаута для главного окна.
* param [in] layout Значение флага установки компоновки.
*/
void MainWindowContainer::setAutoLayout(bool layout)
{
    _autoLayout = layout;
}

/*
* Метод получения виджетов на главном окне.
* return Список виджетов главного окна.
*/
QList<AbstractWidget *> MainWindowContainer::getWidgets()
{
    return _widgets;
}

/*
* Метод получения размера главного окна в зависимости от виджетов.
* return Подсчитанный размер главного окна.
*/
QSize MainWindowContainer::countWindowDimension()
{
    int maxY;
    int maxX;
    int border = 30;
    int i;
    // Высчитать максимальные координаты по осям х и у.
    maxY = _widgets[0]->getPosition().y() + _widgets[0]->getSize().height();
    maxX = _widgets[0]->getPosition().x() + _widgets[0]->getSize().width();
    for(i = 0; i < _widgets.size(); i++)
    {
        if((_widgets[i]->getPosition().x() + _widgets[i]->getSize().width()) > maxX )
        {
            maxX = _widgets[i]->getPosition().x() + _widgets[i]->getSize().width();
        }
        if((_widgets[i]->getPosition().y() + _widgets[i]->getSize().height()) > maxY )
        {
            maxY = _widgets[i]->getPosition().y() + _widgets[i]->getSize().height();
        }
    }
    // Сделать отступ в размере переменной border.
    return QSize(maxX+border, maxY+border);
}

/*
* Метод для распределения виджетов по сетке компоновки.
*/
void MainWindowContainer::setWidgetsIntoGrig()
{
    int minWidth; // Минимальная ширина виджета.
    int minHeight; // Минимальная высота виджета.

    minWidth = _widgets.at(0)->getSize().width();
    minHeight = _widgets.at(0)->getSize().height();

    int i;
    // Вычисляем шаг сетки главного окна.
    for (i = 0; i< _widgets.size(); i++)
    {
        if(minWidth > _widgets.at(i)->getSize().width())
        {
            minWidth = _widgets.at(i)->getSize().width();
        }
        if(minHeight > _widgets.at(i)->getSize().height())
        {
            minHeight = _widgets.at(i)->getSize().height();
        }
    }

    // Для каждого виджета необходимо узнать номер колонки и строки сетки, а также спаны по ширине и высоте.
    for (i = 0; i< _widgets.size(); i++)
    {
        QString name = _widgets.at(i)->getName();
        // Находим положение в колонках сетки.
        int widgetX = _widgets.at(i)->getPosition().x();
        // Номер колонки сетки.
        int colNumber = getCellsCount(widgetX, minWidth);

        // Находим положение в строках сетки.
        int widgetY = _widgets.at(i)->getPosition().y();
        // Номер строки сетки.
        int rowNumber = getCellsCount(widgetY, minHeight);

        // Находим спан по строкам.
        int widgetW = _widgets.at(i)->getSize().width();
        // Растянутость виджета по строкам.
        int rowSpan = getCellsCount(widgetW, minWidth);

        // Находим спан по столбцам.
        int widgetH = _widgets.at(i)->getSize().height();
        // Растянутость виджета по столбцам.
        int colSpan = getCellsCount(widgetH, minHeight);

        _widgets.at(i)->setGridPosition(rowNumber, colNumber, rowSpan, colSpan);
    }
}

/*
* Метод получения номера ячейки сетки по одному из параметров.
* param [in] widgetAttribute Одна из координат, ширина или высота виджета.
* param [in] cellDimension Ширина или высота ячейки сетки.
* return Номер ячейки сетки по вертикали или горизонтали.
*/
int MainWindowContainer::getCellsCount(int widgetAttribute, int cellDimension)
{
    // Ищем целый номер ячейки.
    int dimension = widgetAttribute/cellDimension;
    float div = float (widgetAttribute % cellDimension);
    // Ищем остаток деления параметра на шаг сетки.
    float res = div / ((float)cellDimension);
    // Нужно определить, в какую сторону округлить количество ячеек.
    if( res >= 0.5)
    {
        dimension += 1;
    }
    return dimension;
}
