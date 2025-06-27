#include "Circle.h"

Circle::Circle(double inputRadius)
    : m_radius(inputRadius) // 変数初期化
{
}

double Circle::calculateArea() const // 円の面積
{
    return PI * (m_radius * m_radius);
}

double Circle::calculatePerimeter() const // 円の外周の長さ
{
    return (PI * 2) * m_radius;
}