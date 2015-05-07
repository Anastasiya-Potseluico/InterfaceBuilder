#include "listwidget.h"

ListWidget::ListWidget(QPoint &position, int numberOfWidget) : AbstractItemWidget(position,*(new QSize(256,192)))
{
    _name = QString("ListWidget_").append(QString::number(numberOfWidget));
    _sortingEnabled = true;
    _wordWrap = true;
    addWidgetsForSettings();
}

void ListWidget::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QListWidget");
    xmlWriter.writeAttribute("name",_name);

    AbstractItemWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","wordWrap");
    xmlWriter.writeTextElement("bool",_wordWrap ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","sortingEnabled");
    xmlWriter.writeTextElement("bool",_sortingEnabled ? "true":"false");
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

void ListWidget::drawSelf(QGraphicsScene &scene)
{
    ListWidgetView * view = new ListWidgetView(this);
    scene.addItem(view);
}

void ListWidget::setSettings(QMap<QString, QString> &settings)
{
    AbstractItemWidget::setSettings(settings);

    QString temp;
    temp = settings.value("wordWrap");
    if(temp == "true")
        _wordWrap = true;
    else
        _wordWrap = false;

    temp = settings.value("sortingEnabled");
    if(temp == "true")
        _sortingEnabled = true;
    else
        _sortingEnabled = false;
    _settings.clear();
    addWidgetsForSettings();
}

QString ListWidget::getClassname()
{
    return QString("ListWidget");
}

void ListWidget::addWidgetsForSettings()
{
    _settings.clear();
    QLabel *labelName = new QLabel("Name Of List Widget");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractItemWidget::addWidgetsForSettings();

    QCheckBox *wordWrap = new QCheckBox();
    wordWrap->setText("Word Wrap");
    wordWrap->setChecked(_wordWrap);
    wordWrap->setObjectName("wordWrap");

    QCheckBox *sortingEnabled = new QCheckBox();
    sortingEnabled->setText("Sorting Enabled");
    sortingEnabled->setChecked(_sortingEnabled);
    sortingEnabled->setObjectName("sortingEnabled");

    _settings.append(wordWrap);
    _settings.append(sortingEnabled);
}

