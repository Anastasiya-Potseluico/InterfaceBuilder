#ifndef LABEL_H
#define LABEL_H

#include "abstractwidget.h"
#include "labelview.h"

enum VERTICAL_ALIGNMENT {top, center_v, bottom};
enum HORIZONTAL_ALIGNMENT {Left, center_h, Right, justify};

/*! \file label.h
  *
  * \class Label
  * \brief Класс виджета лейбла.
  * \author Поцелуйко Анастасия
*/
class Label : public AbstractWidget
{
public:
    /*!
     *\brief Конструктор лейбла.
     *\param [in] position Ссылка на позицию, которую должен занять виджет.
     *\param [in] numberOfWidget Порядковый номер виджета.
     */
    Label(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи лейбла в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки лейбла.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для лейбла.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для лейбла в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Текст лейбла*/
    QString _text;
    /*!\brief Флаг переноса слов*/
    bool _wordWrap;
    /*!\brief Вертикальное выравнивание*/
    VERTICAL_ALIGNMENT _verticalAlignment;
    /*!\brief Горизонтальное выравнивание*/
    HORIZONTAL_ALIGNMENT _horizontalAlignment;
};

#endif // LABEL_H
