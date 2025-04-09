#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    
    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a after ++a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a after a++: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    std::cout << "\nArithmetic tests:" << std::endl;
    Fixed c(10);
    Fixed d(3.5f);
    std::cout << "c: " << c << ", d: " << d << std::endl;
    std::cout << "c + d: " << c + d << std::endl;
    std::cout << "c - d: " << c - d << std::endl;
    std::cout << "c * d: " << c * d << std::endl;
    std::cout << "c / d: " << c / d << std::endl;

    std::cout << "\nComparison tests:" << std::endl;
    Fixed e(2);
    Fixed f(4);
    std::cout << "e: " << e << ", f: " << f << std::endl;
    std::cout << "e < f: " << (e < f) << std::endl;
    std::cout << "e > f: " << (e > f) << std::endl;
    std::cout << "e <= f: " << (e <= f) << std::endl;
    std::cout << "e >= f: " << (e >= f) << std::endl;
    std::cout << "e == f: " << (e == f) << std::endl;
    std::cout << "e != f: " << (e != f) << std::endl;

    std::cout << "\nMin/Max tests:" << std::endl;
    std::cout << "min(e, f): " << Fixed::min(e, f) << std::endl;
    std::cout << "max(e, f): " << Fixed::max(e, f) << std::endl;

    std::cout << "\nConversion tests:" << std::endl;
    Fixed g(42.42f);
    std::cout << "g: " << g << std::endl;
    std::cout << "g.toInt(): " << g.toInt() << std::endl;
    std::cout << "g.toFloat(): " << g.toFloat() << std::endl;

    std::cout << "\nDecrement tests:" << std::endl;
    Fixed h(5);
    std::cout << "h: " << h << std::endl;
    std::cout << "--h: " << --h << std::endl;
    std::cout << "h after --h: " << h << std::endl;
    std::cout << "h--: " << h-- << std::endl;
    std::cout << "h after h--: " << h << std::endl;

    return 0;
}
