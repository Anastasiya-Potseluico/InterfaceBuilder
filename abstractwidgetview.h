#ifndef AbstractWidgetView_H
#define AbstractWidgetView_H

#include <QGraphicsItem>
#include <QEvent>
#include <QPainter>
#include <QStyle>
#include <QStyleOptionGraphicsItem>

#include "abstractwidget.h"
#include "cornergrabber.h"
#include "dialogsettings.h"

/*! \file abstractwidgetview.h
  *
  * \class AbstractWidgetView
  * \brief Класс абстрактного представления виджета.
  * \author Поцелуко Анастасия
*/
class AbstractWidgetView : public QGraphicsItem
{

public:
    /*!
    *\brief Конструктор абстрактного представления виджета.
    *\param [in] drawedWidget Указатель на виджет, который будет отрисовываться.
    */
    AbstractWidgetView(AbstractWidget *drawedWidget);

    /*!
    *\brief Переопределение метода отрисовки представления виджета.
    *\param [in] painter QPainter.
    *\param [in] option QStyleOptionGraphicsItem.
    *\param [in] widget QWidget.
    */
    virtual void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget);

    /*!
    *\brief Метод получения прямоугольника, описанного вокруг представления виджета.
    *\return Прямоугольник, описанный вокруг представления виджета.
    */
    QRectF boundingRect() const;

    /*!
    *\brief Метод получения размера авиджета с учетом квадратов для изменения размеров виджетов.
    *\return Прямоугольник, описанный вокруг представления виджета с учетом квадратов для изменения размеров виджетов.
    */
    QRectF widgetSize() const;

protected:
    /*!\brief Виджет для отрисовки*/
    AbstractWidget *_drawedWidget;
    /*!\brief Текст представления виджета*/
    QGraphicsTextItem _itemText;
    /*!\brief Массив квадратов изменения размеров виджета*/
    CornerGrabber*  _corners[4];

    /*!
    *\brief Переопределение метода реагирования на нажатие кнопкой мыши.
    *\param [in] event Событие мыши.
    */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief Переопределение метода реагирования на отпускание кнопки мыши.
    *\param [in] event Событие мыши.
    */
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief Переопределение метода реагирования на движение мышью.
    *\param [in] event Событие мыши.
    */
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief Переопределение метода реагирования на двойной щелчок кнопкой мыши.
    *\param [in] event Событие мыши.
    */
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

    /*!
    *\brief Переопределение метода реагирования на наведение курсором мыши на объект.
    *\param [in] event Событие мыши.
    */
    void hoverEnterEvent ( QGraphicsSceneHoverEvent * event );

    /*!
    *\brief Переопределение метода фильтрации событий на сцене.
    *\param [in] event Событие мыши.
    *\param [in] watched Участвующий в событии объект.
    */
    bool sceneEventFilter ( QGraphicsItem * watched, QEvent * event );

    /*!
    *\brief Переопределение метода реагирования на снятие курсора мыши с объекта.
    *\param [in] event Событие мыши.
    */
    void hoverLeaveEvent ( QGraphicsSceneHoverEvent * event );

private:
    /*!\brief Ширина квадратов изменения размеров виджета*/
    int _cornerWidth;
    /*!\brief Высота квадратов для изменения размеров виджетов*/
    int _cornerHeight;

    /*!\brief Минимально возможная ширина виджета*/
    int _minWidth;
    /*!\brief Минимально возможная высота виджета*/
    int _minHeight;

    /*!
    *\brief Метод для расстановки квадратов для растягивания виджета.
    */
    void setCornerPositions();

    /*!
    *\brief Метод для изменения размеров виджета взависимости от растягивания виджета.
    *\param [in] x Разница в ширине виджета.
    *\param [in] y Разница в высоте виджета.
    */
    void adjustSize(int deltaX, int deltaY);

};

#endif // AbstractWidgetView_H
