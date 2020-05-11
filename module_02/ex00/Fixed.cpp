#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): value(0){
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed &fx): value(fx.value){
    std::cout << "Copy constructor called" << std::endl;
};

/*Fixed::Fixed(Fixed &fx){
    std::cout << "Copy constructor called" << std::endl;
    *this = fx;
};*/

Fixed::~Fixed(void){
    std::cout << "Destructor called" << std::endl;
}
// Overloading of Assignment Operator
void    Fixed::operator=(const Fixed &fx){
    std::cout << "Assignation operator caled" << std::endl;
    value = fx.getRawBits();
}
int     Fixed::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}
void    Fixed::setRawBits(int const raw){
    value = raw;
}