#include "kadai04.square.h"

Square::Square(double inputLength)
    : length(inputLength) // 変数初期化
{
}

double Square::calculateArea() const // 正方形の面積
{
    return length * length;
}

double Square::calculatePerimeter() const // 正方形の外周の長さ
{
    return 4 * length;
}