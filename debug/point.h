#ifndef POINT_H_
#define POINT_H_

class Point {
public:
    Point(double x, double y) : x_(x), y_(y) {}

    double X() const {
        return x_;
    }

    double Y() const {
        return y_;
    }

private:
    double x_;
    double y_;
};

#endif  // POINT_H_