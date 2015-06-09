#ifndef LINEEDIT_H
#define LINEEDIT_H

#include "abstractwidget.h"
#include "lineeditview.h"

/*! \file lineedit.h
  *
  * \class LineEdit
  * \brief Класс виджета строки ввода.
  * \author Поцелуйко Анастасия
*/
class LineEdit : public AbstractWidget
{
public:
    /*!
     *\brief Конструктор строки ввода.
     *\param [in] position Ссылка на позицию, которую должен занять виджет.
     *\param [in] numberOfWidget Порядковый номер виджета.
     */
    LineEdit(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи строки ввода в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки строки ввода.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для строки ввода.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для строки ввода в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Текст строки ввода*/
    QString _text;
    /*!\brief Флаг только на чтение строки ввода*/
    bool _readOnly;
};

#endif // LINEEDIT_H
