#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++" << a++ << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "max: " << max( a, b ) << std::endl;
    std::cout << "min: " << min( a, b ) << std::endl;

    std::cout << std::endl;
    Fixed n1(13);
    Fixed n2(13.0f);

    if (n1-- == n2)
        std::cout << "Son iguales" << std::endl;
    if (n1 != n2)
        std::cout << "Son distintos" << std::endl;
    if (n1 == --n2)
        std::cout << "Son iguales" << std::endl;

    return 0;
}