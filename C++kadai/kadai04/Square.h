#ifndef SQUARE_H
#define SQUARE_H

#include "IShape.h"

class Square : public IShape
{
    public:
    Square(double inputLength); // 変数初期化用
    double calculateArea() const override; // 正方形の面積
    double calculatePerimeter() const override; // 正方形の外周の長さ

    private:
    double m_length; // 1辺の長さ
};

#endif