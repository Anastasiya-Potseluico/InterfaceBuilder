#include "testshaperecognizer.h"

// Метод для загрузки тестового изображения и проверки типа геометрического примитива на нем
bool TestShapeRecognaizer::isCertainShape(QString& path, shapes shape)
{
    cv::Mat source;
    bool isFoundShape = false;
    source = cv::imread(path.toStdString().c_str());
    cv::cvtColor(source, source, CV_BGR2GRAY);
    std::vector<std::vector<cv::Point> > contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(source, contours,hierarchy, CV_RETR_TREE , CV_CHAIN_APPROX_SIMPLE);
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    std::vector<cv::Point> approx;
    switch (shape)
    {
    case tria:
        for(int i = 0; i < contours.size(); i++)
        {
            cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
            if(recognizer->isTriangle(approx))
            {
                isFoundShape = true;
            }
        }
        break;
    case rect:
        for(int i = 0; i < contours.size(); i++)
        {
            cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
            if(recognizer->isRectangle(approx))
            {
                isFoundShape = true;
            }
        }
        break;
    case rou:
        for(int i = 0; i < contours.size(); i++)
        {
            cv::approxPolyDP(cv::Mat(contours[i]), approx, cv::arcLength(cv::Mat(contours[i]), true)*0.02, true);
            if(recognizer->isRound(approx))
            {
                isFoundShape = true;
            }
        }
        break;
    }
    return isFoundShape;
}

//Контур является треугольником (все углы острые)
void TestShapeRecognaizer::test_is_triangle_1()
{
    bool expectedIsTriangle = true;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\1.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 1 - contour is not triangle");
}

//Контур является треугольником (прямоугольный)
void TestShapeRecognaizer::test_is_triangle_2()
{
    bool expectedIsTriangle = true;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\2.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 2 - contour is not triangle");
}

//Контур является треугольником (треугольник в перевернутом состоянии)
void TestShapeRecognaizer::test_is_triangle_3()
{
    bool expectedIsTriangle = true;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\3.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 3 - contour is not triangle");
}

//Контур является треугольником (имеется тупой угол)
void TestShapeRecognaizer::test_is_triangle_4()
{
    bool expectedIsTriangle = true;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\4.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 4 - contour is not triangle");
}

//Контур не является треугольником (на вход подается ромб)
void TestShapeRecognaizer::test_is_triangle_5()
{
    bool expectedIsTriangle = false;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\5.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 5 - contour is triangle");
}

//Контур не является треугольником (контур не замкнутый)
void TestShapeRecognaizer::test_is_triangle_6()
{
    bool expectedIsTriangle = false;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\6.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 6 - contour is triangle");
}

//Контур не является треугольником (контур пересекается с другим контуром)
void TestShapeRecognaizer::test_is_triangle_7()
{
    bool expectedIsTriangle = false;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\7.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 7 - contour is triangle");
}

//Контур является треугольником (нарисован от руки)
void TestShapeRecognaizer::test_is_triangle_8()
{
    bool expectedIsTriangle = true;
    bool realIsTriangle = false;
    QString path = QString("tests\\shapeRecognizer\\isTriangle\\8.png");
    realIsTriangle = isCertainShape(path, tria);
    QVERIFY2(expectedIsTriangle == realIsTriangle, "test 8 - contour is not triangle");
}

//Контур является прямоугольником (типичный прямоугольник)
void TestShapeRecognaizer::test_is_rectangle_1()
{
    bool expectedIsRectangle = true;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\1.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 1 - contour is not rectangle");
}

//Контур является прямоугольником (повернутый прямоугольник)
void TestShapeRecognaizer::test_is_rectangle_2()
{
    bool expectedIsRectangle = true;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\2.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 2 - contour is not rectangle");
}

//Контур является прямоугольником (небольшие отклонения от прямого угла)
void TestShapeRecognaizer::test_is_rectangle_3()
{
    bool expectedIsRectangle = true;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\3.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 3 - contour is not rectangle");
}

//Контур не является прямоугольником (на вход подана трапеция)
void TestShapeRecognaizer::test_is_rectangle_4()
{
    bool expectedIsRectangle = false;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\4.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 4 - contour is rectangle");
}

//Контур не является прямоугольником (на вход подан ромб)
void TestShapeRecognaizer::test_is_rectangle_5()
{
    bool expectedIsRectangle = false;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\5.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 5 - contour is rectangle");
}

//Контур не является прямоугольником (контур разорван)
void TestShapeRecognaizer::test_is_rectangle_6()
{
    bool expectedIsRectangle = false;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\6.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 6 - contour is rectangle");
}

//Контур не является прямоугольником (контур пересечен другим контуром)
void TestShapeRecognaizer::test_is_rectangle_7()
{
    bool expectedIsRectangle = false;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\7.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 7 - contour is rectangle");
}

//Контур является прямоугольником (рисунок от руки)
void TestShapeRecognaizer::test_is_rectangle_8()
{
    bool expectedIsRectangle = true;
    bool realIsRectangle = false;
    QString path = QString("tests\\shapeRecognizer\\isRectangle\\8.png");
    realIsRectangle = isCertainShape(path, rect);
    QVERIFY2(expectedIsRectangle == realIsRectangle, "test 8 - contour is not rectangle");
}

//Контур является кругом (типичный круг)
void TestShapeRecognaizer::test_is_round_1()
{
    bool expectedIsRound = true;
    bool realIsRound = false;
    QString path = QString("tests\\shapeRecognizer\\isRound\\1.png");
    realIsRound = isCertainShape(path, rou);
    QVERIFY2(expectedIsRound == realIsRound, "test 1 - contour is not round");
}

//Контур является кругом (круг с небольшими отклонениями)
void TestShapeRecognaizer::test_is_round_2()
{
    bool expectedIsRound = true;
    bool realIsRound = false;
    QString path = QString("tests\\shapeRecognizer\\isRound\\2.png");
    realIsRound = isCertainShape(path, rou);
    QVERIFY2(expectedIsRound == realIsRound, "test 2 - contour is not round");
}

//Контур не является кругом (на вход подан эллипс)
void TestShapeRecognaizer::test_is_round_3()
{
    bool expectedIsRound = false;
    bool realIsRound = false;
    QString path = QString("tests\\shapeRecognizer\\isRound\\3.png");
    realIsRound = isCertainShape(path, rou);
    QVERIFY2(expectedIsRound == realIsRound, "test 3 - contour is round");
}

//Контур не является кругом (на вход подан шестиугольник)
void TestShapeRecognaizer::test_is_round_4()
{
    bool expectedIsRound = false;
    bool realIsRound = false;
    QString path = QString("tests\\shapeRecognizer\\isRound\\4.png");
    realIsRound = isCertainShape(path, rou);
    QVERIFY2(expectedIsRound == realIsRound, "test 4 - contour is round");
}

//Контур является кругом (рисунок от руки)
void TestShapeRecognaizer::test_is_round_5()
{
    bool expectedIsRound = true;
    bool realIsRound = false;
    QString path = QString("tests\\shapeRecognizer\\isRound\\5.png");
    realIsRound = isCertainShape(path, rou);
    QVERIFY2(expectedIsRound == realIsRound, "test 5 - contour is round");
}

void TestShapeRecognaizer::test_find_geometrical_primitives_1()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 1;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\2.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_2()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 0;
    int expectedTriaCount = 1;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\3.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_3()
{
    int expectedRectCount = 1;
    int expectedRoundCount = 0;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\1.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_4()
{
    int expectedRectCount = 1;
    int expectedRoundCount = 0;
    int expectedTriaCount = 1;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\4.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_5()
{
    int expectedRectCount = 1;
    int expectedRoundCount = 1;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\5.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");
}


void TestShapeRecognaizer::test_find_geometrical_primitives_6()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 1;
    int expectedTriaCount = 1;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\6.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");
}

void TestShapeRecognaizer::test_find_geometrical_primitives_7()
{
    int expectedRectCount = 4;
    int expectedRoundCount = 0;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\7.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");
}

void TestShapeRecognaizer::test_find_geometrical_primitives_8()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 0;
    int expectedTriaCount = 4;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\8.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");
}

void TestShapeRecognaizer::test_find_geometrical_primitives_9()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 3;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\9.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_10()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 0;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\10.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_11()
{
    int expectedRectCount = 2;
    int expectedRoundCount = 1;
    int expectedTriaCount = 3;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\11.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_12()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 0;
    int expectedTriaCount = 0;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\12.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

void TestShapeRecognaizer::test_find_geometrical_primitives_13()
{
    int expectedRectCount = 0;
    int expectedRoundCount = 0;
    int expectedTriaCount = 1;
    cv::Mat source = cv::imread("tests\\shapeRecognizer\\findPrimitives\\13.png");
    ShapeRecognizer * recognizer = new ShapeRecognizer(source);
    recognizer->findGeometricalFeatures();
    QVERIFY2(expectedRectCount == recognizer->getRectangles().size(), "rects size is not as expected");
    QVERIFY2(expectedRoundCount == recognizer->getRounds().size(), "rounds size is not as expected");
    QVERIFY2(expectedTriaCount == recognizer->getTriangles().size(), "triangles size is not as expected");

}

