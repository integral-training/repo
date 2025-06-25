#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "kadai04.ishape.h"

class Rectangle : public IShape
{
    public:
    Rectangle(double inputVertical, double inputWidth); // 変数初期化用
    double calculateArea() const override; // 短形の面積
    double calculatePerimeter() const override; // 短形の外周の長さ
    
    private:
    double vertical; // 縦の長さ
    double width; // 横の長さ
};

#endif