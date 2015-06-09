#ifndef MAINWINDOWCONTAINER_H
#define MAINWINDOWCONTAINER_H

#include "abstractwidget.h"
#include "mainwindowview.h"

/*! \file mainwindowcontainer.h
  *
  * \class MainWindowContainer
  * \brief Класс виджета главного окна.
  * \author Поцелуйко Анастасия
*/
class MainWindowContainer : public AbstractWidget
{
public:
    /*!
     *\brief Конструктор виджета главного окна.
     */
    MainWindowContainer();

    /*!
    *\brief Метод записи главного окна в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки главного окна.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод добавления списка виджетов на главное окно.
    *\param [in] widgets Ссылка на список виджетов.
    */
    void setWidgets(QList<AbstractWidget*> &widgets);

    /*!
    *\brief Метод установки настроек для главного окна.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для главного окна в диалоговом окне.
    */
    void addWidgetsForSettings();

    /*!
    *\brief Метод установки лейаута для главного окна.
    *\param [in] layout Значение флага установки компоновки.
    */
    void setAutoLayout(bool layout);

    /*!
    *\brief Метод получения виджетов на главном окне.
    *\return Список виджетов главного окна.
    */
    QList<AbstractWidget*> getWidgets();

private:
    /*!\brief Список виджетов, расположенных на главном окне*/
    QList <AbstractWidget*> _widgets;
    /*!\brief Заголовок главного окна*/
    QString _windowTitle;
    /*!\brief Флаг автокомпоновки*/
    bool _autoLayout;

    /*!
    *\brief Метод получения размера главного окна в зависимости от виджетов.
    *\return Подсчитанный размер главного окна.
    */
    QSize countWindowDimension();

    /*!
    *\brief Метод для распределения виджетов по сетке компоновки.
    */
    void setWidgetsIntoGrig();

    /*!
    *\brief Метод получения номера ячейки сетки по одному из параметров.
    *\param [in] widgetAttribute Одна из координат, ширина или высота виджета.
    *\param [in] cellDimension Ширина или высота ячейки сетки.
    *\return Номер ячейки сетки по вертикали или горизонтали.
    */
    int getCellsCount(int widgetAttribute, int cellDimension);
};

#endif // MAINWINDOWCONTAINER_H
