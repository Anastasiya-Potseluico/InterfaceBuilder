#include "treewidget.h"

TreeWidget::TreeWidget(QPoint &position, int numberOfWidget): AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("TreeWidget_").append(QString::number(numberOfWidget));
    _headerVisible = true;
    _columnCount = 1;
    addWidgetsForSettings();
}

void TreeWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QTreeWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("attribute");
    xmlWriter.writeAttribute("name","headerVisible");
    xmlWriter.writeTextElement("bool",_headerVisible ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","columnCount");
    xmlWriter.writeTextElement("number",QString::number(_columnCount));
    xmlWriter.writeEndElement();

    int i;
    for(i = 0; i < _columnCount; i++)
    {
        xmlWriter.writeStartElement("column");
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","text");
        xmlWriter.writeStartElement("string");
        xmlWriter.writeAttribute("notr","true");
        xmlWriter.writeCharacters(QString::number(i+1));
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }

    xmlWriter.writeEndElement();
}

void TreeWidget::drawSelf(QGraphicsScene &scene)
{
    TreeWidgetView * view = new TreeWidgetView(this);
    scene.addItem(view);
}

void TreeWidget::setSettings(QMap<QString, QString> &settings)
{
    AbstractItemWidget::setSettings(settings);

    QString tempString = settings.value("headerVisible");
    if(tempString == "true")
        this->_headerVisible = true;
    else
        this->_headerVisible = false;

    tempString = settings.value("col");
    this->_columnCount = tempString.toInt();
}

QString TreeWidget::getClassname()
{
    return QString("TreeWidget");
}

void TreeWidget::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Tree Widget");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractItemWidget::addWidgetsForSettings();

    QCheckBox *headerVisible = new QCheckBox();
    headerVisible->setText("Header Visible");
    headerVisible->setChecked(_headerVisible);
    headerVisible->setObjectName("headerVisible");

    QLabel *labelCol = new QLabel("Column Count");
    QSpinBox *col = new QSpinBox();
    col->setMaximum(100);
    col->setMinimum(0);
    col->setObjectName("col");
    col->setValue(_columnCount);

    _settings.append(headerVisible);
    _settings.append(labelCol);
    _settings.append(labelName);
}
