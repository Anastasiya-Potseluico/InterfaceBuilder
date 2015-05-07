#include "tablewidget.h"

TableWidget::TableWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TableWidget_").append(QString::number(numberOfWidget));
    _showGrid = true;
    _rowCount = 0;
    _columnCount = 0;
    addWidgetsForSettings();
}

void TableWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QTableWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","showGrid");
    xmlWriter.writeTextElement("bool",_showGrid ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","rowCount");
    xmlWriter.writeTextElement("number",QString::number(_rowCount));
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","columnCount");
    xmlWriter.writeTextElement("number",QString::number(_columnCount));
    xmlWriter.writeEndElement();

    int i;
    for(i = 0; i < _rowCount; i++)
    {
        xmlWriter.writeEmptyElement("row");
    }

    for(i = 0; i < _columnCount; i++)
    {
        xmlWriter.writeEmptyElement("column");
    }

    xmlWriter.writeEndElement();
}

void TableWidget::drawSelf(QGraphicsScene &scene)
{
    TableWidgetView * view = new TableWidgetView(this);
    scene.addItem(view);
}

void TableWidget::setSettings(QMap<QString, QString> &settings)
{
    AbstractItemWidget::setSettings(settings);

    QString tempString = settings.value("showGrid");
    if(tempString == "true")
        this->_showGrid = true;
    else
        this->_showGrid = false;

    tempString = settings.value("row");
    this->_rowCount = tempString.toInt();
    tempString = settings.value("col");
    this->_columnCount = tempString.toInt();
    _settings.clear();
    addWidgetsForSettings();
}

QString TableWidget::getClassname()
{
    return QString("TableWidget");
}

void TableWidget::addWidgetsForSettings()
{
    _settings.clear();
    QLabel *labelName = new QLabel("Name Of Table Widget");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractItemWidget::addWidgetsForSettings();

    QCheckBox *showGrid = new QCheckBox();
    showGrid->setText("Show Grid");
    showGrid->setChecked(_showGrid);
    showGrid->setObjectName("showGrid");

    QLabel *labelRow = new QLabel("Row Count");
    QSpinBox *row = new QSpinBox();
    row->setMaximum(100);
    row->setMinimum(0);
    row->setObjectName("row");
    row->setValue(_rowCount);

    QLabel *labelCol = new QLabel("Column Count");
    QSpinBox *col = new QSpinBox();
    col->setMaximum(100);
    col->setMinimum(0);
    col->setObjectName("col");
    col->setValue(_columnCount);

    _settings.append(showGrid);
    _settings.append(labelRow);
    _settings.append(row);
    _settings.append(labelCol);
    _settings.append(col);
}
