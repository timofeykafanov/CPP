#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(x), _y(y) {}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y) {}

Point::Point(Point const& other) {
    *this = other;
}

Point::~Point() {}

Point& Point::operator=(Point const& other) {
    if (this != &other) {
        const_cast<Fixed&>(_x) = other._x;
        const_cast<Fixed&>(_y) = other._y;
    }
    return *this;
}

Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

