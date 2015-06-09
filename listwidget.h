#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include "abstractitemwidget.h"
#include "listwidgetview.h"

/*! \file listwidget.h
  *
  * \class ListWidget
  * \brief Класс виджета списка.
  * \author Поцелуйко Анастасия
*/
class ListWidget : public AbstractItemWidget
{
public:
    /*!
     *\brief Конструктор виджета списка.
     *\param [in] position Ссылка на позицию, которую должен занять виджет.
     *\param [in] numberOfWidget Порядковый номер виджета.
     */
    ListWidget(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи списка в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки списка.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для списка.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для списка в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Флаг переноса слов*/
    bool _wordWrap;
    /*!\brief Флаг возможности сортировки*/
    bool _sortingEnabled;
};

#endif // LISTWIDGET_H
