#ifndef COMBOBOX_H
#define COMBOBOX_H

#include "abstractwidget.h"
#include "comboboxview.h"

/*! \file combobox.h
  *
  * \class ComboBox
  * \brief Класс виджета комбобокса.
  * \author Поцелуко Анастасия
*/
class ComboBox : public AbstractWidget
{
public:
    /*!
    *\brief Конструктор комбобокса.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] size Размер создаваемого виджета.
    */
    ComboBox(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи комбобокса в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки комбобокса.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для комбобокса.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для комбобокса в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Айтемы комбобокса*/
    QStringList _items;
    /*!\brief Флаг возможности редактирования айтемов*/
    bool _isEditable;
    /*!\brief Выбранный индекс комбобокса*/
    int _currentIndex;

};

#endif // COMBOBOX_H
