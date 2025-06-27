#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"

class Rectangle : public IShape
{
    public:
    Rectangle(double inputVertical, double inputWidth); // 変数初期化用
    double calculateArea() const override; // 短形の面積
    double calculatePerimeter() const override; // 短形の外周の長さ
    
    private:
    double m_vertical; // 縦の長さ
    double m_width; // 横の長さ
};

#endif