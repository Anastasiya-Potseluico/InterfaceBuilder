#ifndef CHECKBOX_H
#define CHECKBOX_H

#include "abstractbutton.h"
#include "checkboxview.h"

/*! \file checkbox.h
  *
  * \class CheckBox
  * \brief Класс виджета чекбокса.
  * \author Поцелуко Анастасия
*/
class CheckBox : public AbstractButton
{
public:
    /*!
    *\brief Конструктор чекбокса.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    CheckBox(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи чекбокса в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки чекбокса.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для чекбокса.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для чекбокса в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Возможность трех состояний*/
    bool _tristate;
};

#endif // CHECKBOX_H
