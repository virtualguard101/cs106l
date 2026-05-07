#include <cmath>

class Shape {
public:
    virtual double Area() const = 0;
};

class Circle : public Shape {
public:
    // constructor
    Circle(double radius) : _radius(radius) {};
    double Area() const override {
        return M_PI * _radius * _radius;
    }

private:
    double _radius;
};

class Rectangle : public Shape {
public:
    // constructor
    Rectangle(double width, double height):
        _width(width), _height(height) {};
    double Area() const override {
        return _width * _height;
    }

private:
    double _width, _height;
};