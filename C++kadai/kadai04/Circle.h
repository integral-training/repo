#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"

class Circle : public IShape
{
    public:
    Circle(double inputRadius); // 変数初期化用
    double calculateArea() const override; // 円の面積
    double calculatePerimeter() const override; // 円の外周の長さ

    private:
    const double PI = 3.14159; // 円周率
    double m_radius; // 半径
};

#endif