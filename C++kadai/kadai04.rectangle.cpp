#include "kadai04.rectangle.h"

Rectangle::Rectangle(double inputVertical, double inputWidth)
    : vertical(inputVertical), width(inputWidth) // 変数初期化
{
}

double Rectangle::calculateArea() const // 短形の面積
{
    return vertical * width;
}

double Rectangle::calculatePerimeter() const // 短形の外周の長さ
{
    return (width + vertical) * 2;
}