#ifndef ABSTRACTWIDGET_H
#define ABSTRACTWIDGET_H

#include <QCheckBox>
#include <QFile>
#include <QGraphicsScene>
#include <QLabel>
#include <QLineEdit>
#include <QMap>
#include <QObject>
#include <QPoint>
#include <QSize>
#include <QSpinBox>
#include <QString>
#include <QXmlStreamWriter>

/*! \file abstractwidget.h
  *
  * \class AbstractWidget
  * \brief Класс абстрактного виджета.
  * \author Поцелуко Анастасия
*/

class AbstractWidget : public QObject
{

    Q_OBJECT

public:

    /*!
    *\brief Конструктор абстрактного виджета.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    AbstractWidget(QPoint& position, QSize &size);

    /*!
    *\brief Метод испускания сигнала изменения настроек виджета.
    */
    void emitSettingsChangedSignal();

    /*!
    *\brief Метод отрисовки абстрактного виджета.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief Метод установки настроек для абстрактного виджета.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // Устанавливаем настройку имени виджета.
        QString tempString = settings.value("name");
        this->_name = tempString;
        // Устанавливаем настройку видимости виджета.
        tempString = settings.value("enabled");
        if(tempString == "true")
            this->_enabled = true;
        else
            this->_enabled = false;
    }

    /*!
    *\brief Метод получения позиции виджета.
    *\return Текущая позиция виджета.
    */
    QPoint getPosition();

    /*!
    *\brief Метод получения размера виджета.
    *\return Текущий размер виджета.
    */
    QSize getSize();

    /*!
    *\brief Метод получения виджетов для настроек виджета.
    *\return Список виджетов для настроек виджета.
    */
    QList<QWidget*> getSettings();

    /*!
    *\brief Метод получения имени виджета.
    *\return Имя виджета в виде строки.
    */
    QString getName();

    /*!
    *\brief Метод изменения размера виджета.
    *\param [in] size Ссылка на новый размер виджета.
    */
    void setSize(QSize &size);

    /*!
    *\brief Метод изменения позиции виджета.
    *\param [in] size Ссылка на новую позицию виджета.
    */
    void setPosition(QPoint &position);

    /*!
    *\brief Метод записи абстрактного виджета в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
            // Записываем имя виджета.
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","geometry");
            // Записываем размер виджета.
            xmlWriter.writeStartElement("rect");
            xmlWriter.writeTextElement("x",QString::number(this->_position.x()));
            xmlWriter.writeTextElement("y",QString::number(this->_position.y()));
            xmlWriter.writeTextElement("width",QString::number(this->_size.width()));
            xmlWriter.writeTextElement("height",QString::number(this->_size.height()));
            xmlWriter.writeEndElement();
            xmlWriter.writeEndElement();
            // Записываем видимость виджета.
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","enabled");
            xmlWriter.writeTextElement("bool",_enabled ? "true":"false");
            xmlWriter.writeEndElement();
    }

    /*!
    *\brief Метод для добавления нужных виджетов настроек для абстрактной кнопки в диалоговом окне.
    */
    virtual  void addWidgetsForSettings()
    {
        QCheckBox *enabled = new QCheckBox();
        enabled->setText("Widget is enabled");
        enabled->setChecked(_enabled);
        enabled->setObjectName("enabled");
        _settings.append(enabled);
    }

    void setGridPosition(int row, int col, int rowSpan, int colSpan);

    void writeItemIntoFile(QXmlStreamWriter &xmlWriter);

    int col();
    int row();
    int colSpan();
    int rowSpan();

signals:
    /*!
    *\brief Сигнал, испускающийся при изменении настроек виджета.
    */
    void settingsChanged();

protected:
    /*!\brief Размер виджета*/
    QSize _size;
    /*!\brief Позиция виджета*/
    QPoint _position;
    /*!\brief Имя виджета*/
    QString _name;
    /*!\brief Видимость виджета*/
    bool _enabled;
    /*!\brief Список настроек для виджета*/
    QList<QWidget*> _settings;

    //???!!!!
    int _gridCol; // Положение виджета в сетке лейаута (колонка).
    int _gridRow; // Положение виджета в сетке лейаута (строка).
    int _colSpan; // Сколько колонок занимает виджет в лейауте.
    int _rowSpan; // Сколько строк занимает виджет в лейауте.
};

#endif // ABSTRACTWIDGET_H
