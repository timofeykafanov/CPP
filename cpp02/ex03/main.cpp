#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

int main(void) {
    bool result;

    std::cout << "Test 1: Point outside triangle: 0,0 : 1,0 : 0,1 : 2,2" << std::endl;
    result = bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(2, 2));
    if (result)
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    std::cout << std::endl;

    std::cout << "Test 2: Point inside of triangle: 0,0 : 1,0 : 0,1 : 0.4,0.4" << std::endl;
    result = bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.4f, 0.4f));
    if (result)
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;

    std::cout << std::endl;

    std::cout << "Test 3: Point on edge of triangle: 0,0 : 1,0 : 0,1 : 0.5,0.5" << std::endl;
    result = bsp(Point(0, 0), Point(1, 0), Point(0, 1), Point(0.5f, 0.5));
    if (result)
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    return 0;
}