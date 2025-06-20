#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "point.h"

class Circle {
public:
    Circle(const Point& center, double radius)
        : center_(center), radius_(radius) {}

    Point Center() const {
        return center_;
    }

    double Radius() const {
        return radius_;
    }

private:
    Point center_;
    double radius_;
};

#endif  // CIRCLE_H_