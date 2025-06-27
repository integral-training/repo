#include "Square.h"

Square::Square(double inputLength)
    : m_length(inputLength) // 変数初期化
{
}

double Square::calculateArea() const // 正方形の面積
{
    return m_length * m_length;
}

double Square::calculatePerimeter() const // 正方形の外周の長さ
{
    return 4 * m_length;
}