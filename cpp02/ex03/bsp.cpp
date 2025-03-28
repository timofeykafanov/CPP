#include "Point.hpp"

Fixed triangleArea(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3) {
    Fixed area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
    return area >= Fixed(0) ? area : area * -1;

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

    
    Fixed sqaure1 = (x - x1) * (y2 - y1) - (x2 - x1) * (y - y1);
    Fixed sqaure2 = (x - x2) * (y3 - y2) - (x3 - x2) * (y - y2);
    Fixed sqaure3 = (x - x3) * (y1 - y3) - (x1 - x3) * (y - y3);


    return true;
}