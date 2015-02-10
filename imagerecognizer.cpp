#include "imagerecognizer.h"

ImageRecognizer::ImageRecognizer()
{
   // _inputImage = input;
}

/*Метод для предварительной обработки изображения*/
void ImageRecognizer::prepareImage()
{
    //Гауссово размытие
    cv::cvtColor(_inputImage, _inputImage, CV_BGR2GRAY);
    //Детектор границ Канни
    cv::Canny(_inputImage, _inputImage, 0, 50, 5);
}

std::vector ImageRecognizer::findGeometricalFeatures()
{

}

/*Метод для определения, является ли контур треугольником */
bool ImageRecognizer::isTriangle(std::vector<cv::Point> & contour)
{
    return (approx.size() == 3);
}

/*Метод для определения, является ли контур прямоугольником */
bool ImageRecognizer::isRectangle(std::vector<cv::Point> & contour)
{
    if (contour.size() >= 4 && contour.size() <= 6)
    {
        // Количество ребер контура.
        int vtc = contour.size();

        // Получим косинусы между всеми векторами контура.
        std::vector<double> cos;
        for (int j = 2; j < vtc+1; j++)
        {
            cos.push_back(angle(contour[j%vtc], contour[j-2], contour[j-1]));
        }

        // Отсортируем все косинусы по увеличению.
        std::sort(cos.begin(), cos.end());

        // Берем максимальный и минимальный косинусы.
        double mincos = cos.front();
        double maxcos = cos.back();

        // Проверяем правильность условия для прямоугольника: 4 стороны и прямые углы.
        if (vtc == 4 && mincos >= -0.1 && maxcos <= 0.3)
            return true;
    }
    return false;
}

/*Метод для определения, является ли контур эллипсом */
bool ImageRecognizer::isEllipse(std::vector<cv::Point> & contour)
{
    if(contour.size() > 6)
    {
        // Detect and label circles
        double area = cv::contourArea(contour);
        cv::Rect r = cv::boundingRect(contour);
        int radius = r.width / 2;

        if (std::abs(1 - ((double)r.width / r.height)) <= 0.2 &&
                std::abs(1 - (area / (CV_PI * std::pow(radius, 2)))) <= 0.2)
            return true;
    }
    return false;
}

/*Метод для определения угла между векторами pt0->pt1 и pt0->pt2 */
double ImageRecognizer::angle(cv::Point pt1, cv::Point pt2, cv::Point pt0)
{
    double dx1 = pt1.x - pt0.x;
    double dy1 = pt1.y - pt0.y;
    double dx2 = pt2.x - pt0.x;
    double dy2 = pt2.y - pt0.y;
    return (dx1*dx2 + dy1*dy2)/sqrt((dx1*dx1 + dy1*dy1)*(dx2*dx2 + dy2*dy2) + 1e-10);
}
