#ifndef ABSTRACTBUTTON_H
#define ABSTRACTBUTTON_H

#include <QImage>

#include "abstractwidget.h"

/*! \file abstractbutton.h
  *
  * \class AbstractButton
  * \brief Класс абстрактной кнопки.
  * \author Поцелуко Анастасия
*/

class AbstractButton : public AbstractWidget
{
public:
    /*!
    *\brief Конструктор абстрактной кнопки.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    AbstractButton(QPoint &position, QSize &size);

    /*!
    *\brief Метод отрисовки абстрактной кнопки.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief Метод установки настроек для абстрактной кнопки.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // Устанавливаем настройки, общие для всех виджетов.
        AbstractWidget::setSettings(settings);
        // Ищем настройки текста кнопки
        QString tempString = settings.value("text");
        _text = tempString;
        // Имем настройки для возможности нажатия кнопки.
        tempString = settings.value("checkable");
        if(tempString == "true")
            _checkable = true;
        else
            _checkable = false;
        // Ищем настройки для флага нажатости кнопки.
        tempString = settings.value("isChecked");
        if(tempString == "true")
            _isChecked = true;
        else
            _isChecked = false;
    }

    /*!
    *\brief Метод записи абстрактной кнопки в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        // Записываем в файл сначала свойства, общие для всех виджетов.
        AbstractWidget::writeSelfIntoFile(xmlWriter);
        // Записываем текст кнопки.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","text");
        xmlWriter.writeTextElement("string",_text);
        xmlWriter.writeEndElement();
        // Записываем флаг возможности нажатия кнопки.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","checkable");
        xmlWriter.writeTextElement("bool",_checkable ? "true":"false");
        xmlWriter.writeEndElement();
        // Если кнопку можно нажать, записываем состояние нажатости кнопки.
        if(_checkable)
        {
            xmlWriter.writeStartElement("property");
            xmlWriter.writeAttribute("name","checked");
            xmlWriter.writeTextElement("bool",_isChecked ? "true":"false");
            xmlWriter.writeEndElement();
        }
    }

    /*!
    *\brief Метод для добавления нужных виджетов настроек для абстрактной кнопки в диалоговом окне.
    */
    virtual void addWidgetsForSettings()
    {
        // Добавляем виджеты для общих настроек.
        AbstractWidget::addWidgetsForSettings();
        // Добавляем поле для ввода текста кнопки.
        QLabel *textLabel = new QLabel("Text");
        QLineEdit *text = new QLineEdit();
        text->setObjectName("text");
        text->setText(_text);
        // Добавляем чекбокс для редактирования возможности нажатия кнопки.
        QCheckBox *checkable = new QCheckBox();
        checkable->setText("Button is checkable");
        checkable->setChecked(_checkable);
        checkable->setObjectName("checkable");
        // Добавляем чекбокс для редактирования состояния нажатости кнопки.
        QCheckBox *isChecked = new QCheckBox();
        isChecked->setText("Button is checked");
        isChecked->setChecked(_isChecked);
        isChecked->setObjectName("isChecked");
        if(_checkable)
        {
            isChecked->setEnabled(true);
        }
        else
        {
            isChecked->setEnabled(false);
        }
        // Все созданные виджеты добавляем в список виджетов для настроек.
        _settings.append(textLabel);
        _settings.append(text);
        _settings.append(checkable);
        _settings.append(isChecked);
    }

protected:
    /*!\brief Флаг возможности кнопки быть нажатой*/
    bool _checkable;
    /*!\brief Флаг нажатости кнопки*/
    bool _isChecked;
    /*!\brief Текст, отображающийся внутри кнопки*/
    QString _text;
};

#endif // ABSTRACTBUTTON_H
