#include "Point.hpp"
#include <iostream>

Fixed triangleArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3) {
    Fixed area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
    return area >= Fixed(0) ? area : area * Fixed(-1);

}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
    Fixed const x = point.getX();
    Fixed const y = point.getY();
    Fixed const x1 = a.getX();
    Fixed const y1 = a.getY();
    Fixed const x2 = b.getX();
    Fixed const y2 = b.getY();
    Fixed const x3 = c.getX();
    Fixed const y3 = c.getY();

    Fixed square = (triangleArea(x1, y1, x2, y2, x3, y3));
    Fixed square1 = (triangleArea(x, y, x2, y2, x3, y3));
    Fixed square2 = (triangleArea(x1, y1, x, y, x3, y3));
    Fixed square3 = (triangleArea(x1, y1, x2, y2, x, y));

    std::cout << "square: " << square << std::endl;
    std::cout << "square1: " << square1 << std::endl;
    std::cout << "square2: " << square2 << std::endl;
    std::cout << "square3: " << square3 << std::endl;

    if (square1 == Fixed(0) || square2 == Fixed(0) || square3 == Fixed(0)) {
        return false;
    }
    if (square == square1 + square2 + square3) {
        return true;
    }


    return false;
}