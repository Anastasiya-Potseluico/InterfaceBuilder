#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include "graphicsviewview.h"

enum NEEDED_SCROLL_PANELS {always_on, always_off, as_needed};

/*! \file graphicsview.h
  *
  * \class GraphicsView
  * \brief Класс виджета графического отображения.
  * \author Поцелуйко Анастасия
*/
class GraphicsView : public AbstractWidget
{
public:
   /*!
    *\brief Конструктор графиксвью.
    *\param [in] position Ссылка на позицию, которую должен занять виджет.
    *\param [in] numberOfWidget Порядковый номер виджета.
    */
    GraphicsView(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи графиксвью в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки графиксвью.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для графиксвью.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для графиксвью в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Флаг интерактивности*/
    bool _interactive;
    /*!\brief Необходимость вертикальной прокрутки*/
    NEEDED_SCROLL_PANELS _verticalScrollPanel;
    /*!\brief Необходимость горизонтальной прокрутки*/
    NEEDED_SCROLL_PANELS _horizontalScrollPanel;
};

#endif // GRAPHICSVIEW_H
