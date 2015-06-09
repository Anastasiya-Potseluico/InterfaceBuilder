#ifndef ABSTRACTITEMWIDGET_H
#define ABSTRACTITEMWIDGET_H

#include "abstractwidget.h"

/*! \file abstractwidget.h
  *
  * \class AbstractItemWidget
  * \brief Класс абстрактного списка данных.
  * \author Поцелуко Анастасия
*/

class AbstractItemWidget : public AbstractWidget
{
public:
    /*!
    *\brief Конструктор абстрактного списка данных.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    AbstractItemWidget(QPoint &position, QSize &size);

    /*!
    *\brief Метод отрисовки абстрактного списка данных.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    virtual void drawSelf(QGraphicsScene &scene) = 0;

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    virtual QString getClassname() = 0;

    /*!
    *\brief Метод установки настроек для абстрактного списка данных.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    virtual void setSettings(QMap<QString, QString> &settings)
    {
        // Устанавливаем настройки, общие для всех виджетов.
        AbstractWidget::setSettings(settings);
        // Устанавливаем настройку навигации по кнопке Tab.
        QString tempString = settings.value("tabKeyNavigate");
        if(tempString == "true")
            this->_tabKeyNavigate = true;
        else
            this->_tabKeyNavigate = false;
        // Устанавливаем настройку автопрокрутки.
        tempString = settings.value("autoScroll");
        if(tempString == "true")
            this->_autoScroll = true;
        else
            this->_autoScroll = false;
    }

    /*!
    *\brief Метод записи абстрактного списка данных в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    virtual void writeSelfIntoFile(QXmlStreamWriter &xmlWriter)
    {
        // Записываем все общие свойства виджета.
        AbstractWidget::writeSelfIntoFile(xmlWriter);

        // Записываем свойство навигации по кнопке Tab.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","tabKeyNavigate");
        xmlWriter.writeTextElement("bool",_tabKeyNavigate ? "true":"false");
        xmlWriter.writeEndElement();

        // Записываем свойство автопрокрутки.
        xmlWriter.writeStartElement("property");
        xmlWriter.writeAttribute("name","autoScroll");
        xmlWriter.writeTextElement("bool",_autoScroll ? "true":"false");
        xmlWriter.writeEndElement();
    }

    /*!
    *\brief Метод для добавления нужных виджетов настроек для абстрактного списка данных в диалоговом окне.
    */
    virtual void addWidgetsForSettings()
    {
        // Добавляем все общие виджеты для настроек.
        AbstractWidget::addWidgetsForSettings();

        // Добавляем флаг для настройки навигации по кнопке Tab.
        QCheckBox *tabKeyNavigate = new QCheckBox();
        tabKeyNavigate->setText("Tab Key Navigate");
        tabKeyNavigate->setChecked(_tabKeyNavigate);
        tabKeyNavigate->setObjectName("tabKeyNavigate");

        // Добавляем флаг для настройки автопрокрутки.
        QCheckBox *autoscroll = new QCheckBox();
        autoscroll->setText("Autoscroll");
        autoscroll->setChecked(_autoScroll);
        autoscroll->setObjectName("autoscroll");

        // Добавляем все созданные виджеты в массив настроек.
        _settings.append(tabKeyNavigate);
        _settings.append(autoscroll);
    }

protected:
    /*!\brief Флаг автопрокрутки абстрактного списка данных*/
    bool _autoScroll;
    /*!\brief Флаг возможности навигации по списку с помощью кнопки Tab*/
    bool _tabKeyNavigate;

};

#endif // ABSTRACTITEMWIDGET_H
