#include "kadai04.circle.h"

Circle::Circle(double inputRadius)
    : radius(inputRadius) // 変数初期化
{
}

double Circle::calculateArea() const // 円の面積
{
    return 3.14159 * (radius * radius);
}

double Circle::calculatePerimeter() const // 円の外周の長さ
{
    return (3.14159 * 2) * radius;
}