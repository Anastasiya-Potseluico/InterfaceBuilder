#include "graphicsview.h"

GraphicsView::GraphicsView(QPoint &position, int numberOfWidget):AbstractWidget(position,*(new QSize(256,192)))
{
    _interactive = false;
    _verticalScrollPanel = as_needed;
    _horizontalScrollPanel = as_needed;
    _name = QString("GraphicsView").append(QString::number(numberOfWidget));
    addWidgetsForSettings();
}

void GraphicsView::drawSelf(QGraphicsScene &scene)
{
    GraphicsViewView * view = new GraphicsViewView(this);
    scene.addItem(view);
}

void GraphicsView::setSettings(QMap<QString, QString> &settings)
{
    AbstractWidget::setSettings(settings);
    QString temp;
    temp = settings.value("interactive");
    if(temp == "true")
        _interactive = true;
    else
        _interactive = false;
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

QString GraphicsView::getClassname()
{
    return QString("GraphicsView");
}

void GraphicsView::addWidgetsForSettings()
{
    QLabel *labelName = new QLabel("Name Of Graphics View");
    QLineEdit *name = new QLineEdit();
    name->setObjectName("name");
    name->setText(_name);
    _settings.append(labelName);
    _settings.append(name);

    AbstractWidget::addWidgetsForSettings();

    QCheckBox *interactive = new QCheckBox();
    interactive->setText("Interactive");
    interactive->setChecked(_interactive);
    interactive->setObjectName("interactive");

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

void GraphicsView::writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("widget");
    xmlWriter.writeAttribute("class","QGraphicsView");
    xmlWriter.writeAttribute("name",_name);

    AbstractWidget::writeSelfIntoFile(xmlWriter);

    xmlWriter.writeStartElement("property");
    xmlWriter.writeAttribute("name","interactive");
    xmlWriter.writeTextElement("bool",_interactive ? "true":"false");
    xmlWriter.writeEndElement();

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
