#ifndef TESTSHAPERECOGNIZER_H
#define TESTSHAPERECOGNIZER_H
#include <QtTest>
#include "shaperecognizer.h"

enum shapes {tria, rect, rou};

class TestShapeRecognaizer: public QObject
{
    Q_OBJECT

private slots:
    //“есты на проверку, принадлежит ли контур к классу треугольника или нет
    void test_is_triangle_1();
    void test_is_triangle_2();
    void test_is_triangle_3();
    void test_is_triangle_4();
    void test_is_triangle_5();
    void test_is_triangle_6();
    void test_is_triangle_7();
    void test_is_triangle_8();

    //“есты на проверку, принадлежит ли контур к классу пр€моугольника или нет
    void test_is_rectangle_1();
    void test_is_rectangle_2();
    void test_is_rectangle_3();
    void test_is_rectangle_4();
    void test_is_rectangle_5();
    void test_is_rectangle_6();
    void test_is_rectangle_7();
    void test_is_rectangle_8();

    //“есты на проверку, принадлежит ли контур к классу круга или нет
    void test_is_round_1();
    void test_is_round_2();
    void test_is_round_3();
    void test_is_round_4();
    void test_is_round_5();

    //“есты на проверку заполнени€ массивов геометрических примитивов
    void test_find_geometrical_primitives_1();
    void test_find_geometrical_primitives_2();
    void test_find_geometrical_primitives_3();
    void test_find_geometrical_primitives_4();
    void test_find_geometrical_primitives_5();
    void test_find_geometrical_primitives_6();
    void test_find_geometrical_primitives_7();
    void test_find_geometrical_primitives_8();
    void test_find_geometrical_primitives_9();
    void test_find_geometrical_primitives_10();
    void test_find_geometrical_primitives_11();
    void test_find_geometrical_primitives_12();
    void test_find_geometrical_primitives_13();

private:
    bool isCertainShape(QString &path, shapes shape);


};

#endif // TESTSHAPERECOGNIZER_H
