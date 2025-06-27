#ifndef ISHAPE_H
#define ISHAPE_H

class IShape
{
    public:
    virtual double calculateArea() const = 0; // 面積計算
    virtual double calculatePerimeter() const = 0; // 外周の長さ計算
    virtual ~IShape() = default;
};

#endif