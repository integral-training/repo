#include "Rectangle.h"

Rectangle::Rectangle(double inputVertical, double inputWidth)
    : m_vertical(inputVertical), m_width(inputWidth) // 変数初期化
{
}

double Rectangle::calculateArea() const // 短形の面積
{
    return m_vertical * m_width;
}

double Rectangle::calculatePerimeter() const // 短形の外周の長さ
{
    return (m_width + m_vertical) * 2;
}