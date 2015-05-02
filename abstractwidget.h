#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QSize>
#include <QPoint>
#include <QString>
#include <QGraphicsScene>
#include <QFile>
#include <QCheckBox>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QMap>
#include <QXmlStreamWriter>



/* Класс абстрактного виджета.
*/
class AbstractWidget
{
public:
    AbstractWidget(QPoint& position, QSize &size);
    virtual void drawSelf(QGraphicsScene &scene) = 0;
    virtual QString getClassname() = 0;

    virtual void setSettings(QMap<QString, QString> &settings)
    {
        QString tempString = settings.value("name");
        this->_name = tempString;
        tempString = settings.value("enabled");
        if(tempString == "true")
            this->_enabled = true;
        else
            this->_enabled = false;
    }

    QPoint getPosition();
    QSize getSize();
    QList<QWidget*> getSettings();
    QString getName();
    void setSize(QSize &size);
    void setPosition(QPoint &position);
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","geometry");
            xmlWriter.writeStartElement("rect");
            xmlWriter.writeTextElement("x",QString::number(this->_position.x()));
            xmlWriter.writeTextElement("y",QString::number(this->_position.y()));
            xmlWriter.writeTextElement("width",QString::number(this->_size.width()));
            xmlWriter.writeTextElement("height",QString::number(this->_size.height()));
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();

            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","enabled");
            xmlWriter.writeTextElement("bool",_enabled ? "true":"false");
            xmlWriter.writeEndElement();
    }

protected:
    QSize _size; // Размер видета.
    QPoint _position; // Позиция виджета на главное окне.
    QString _name; // Имя виджета.
    bool _enabled; // Видимость виджета.
    QList<QWidget*> _settings;
    void addWidgetsForSettings();
};

#endif // ABSTRACTWIDGET_H
