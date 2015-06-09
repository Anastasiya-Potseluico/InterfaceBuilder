#ifndef PROGRESSBAR_H
#define PROGRESSBAR_H

#include "abstractwidget.h"
#include "progressbarview.h"

/*! \file progressbar.h
  *
  * \class ProgressBar
  * \brief Класс виджета строки прогресса.
  * \author Поцелуйко Анастасия
*/
class ProgressBar : public AbstractWidget
{
public:
    /*!
     *\brief Конструктор виджета прогресса.
     *\param [in] position Ссылка на позицию, которую должен занять виджет.
     *\param [in] numberOfWidget Порядковый номер виджета.
     */
    ProgressBar(QPoint &position, int numberOfWidget);

    /*!
    *\brief Метод записи прогресс-бара в файл.
    *\param [in] xmlWriter Ссылка на класс записи в файл в xml формате.
    */
    void writeSelfIntoFile(QXmlStreamWriter &xmlWriter);

    /*!
    *\brief Метод отрисовки прогресс-бара.
    *\param [in] position Ссылка на сцену, на которой должна производиться отрисовка.
    */
    void drawSelf(QGraphicsScene &scene);

    /*!
    *\brief Метод установки настроек для прогресс-бара.
    *\param [in] settings Ссылка на карту соответствий настроек и их значений в строковом представлении.
    */
    void setSettings(QMap<QString, QString> &settings);

    /*!
    *\brief Метод получения имени класса.
    *\return Имя класса в виде строки.
    */
    QString getClassname();

    /*!
    *\brief Метод для добавления нужных виджетов настроек для прогресс-бара в диалоговом окне.
    */
    void addWidgetsForSettings();

private:
    /*!\brief Флаг видимости текста*/
    bool _textVisible;
    /*!\brief Текущее значение прогресса*/
    int _value;
    /*!\brief Флаг обратного отображения*/
    bool _invertedAppearance;
    /*!\brief Минимальное значение прогресса*/
    int _minValue;
    /*!\brief Максимальное значение прогресса*/
    int _maxValue;
};

#endif // PROGRESSBAR_H
