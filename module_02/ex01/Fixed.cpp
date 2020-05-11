#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//constructors & destructor:
Fixed::Fixed(void): value(0){std::cout << "Default constructor called" << std::endl;}
Fixed::Fixed(const Fixed &fx): value(fx.value){std::cout << "Copy constructor called" << std::endl;}
Fixed::Fixed(float f){std::cout << "Float constructor called" << std::endl; value = roundf(f * (1 << fractional_bits));}
Fixed::Fixed(int i){std::cout << "Int constructor called" << std::endl; value = i << fractional_bits;}
Fixed::~Fixed(void){std::cout << "Destructor called" << std::endl;}

// Overloading of Assignment Operator
void    Fixed::operator=(const Fixed &fx){
    std::cout << "Assignation operator caled" << std::endl;
    value = fx.getRawBits();
}

//get & set
int     Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (value);
}

int     Fixed::getFractionalBits(void) const{
    return (fractional_bits);
}

void    Fixed::setRawBits(int const raw){
    value = raw;
}

//other
int     Fixed::toInt(void) const
{
    return (value >> fractional_bits);
}

float   Fixed::toFloat(void) const
{
    return ((double)value / (double)(1 << fractional_bits));
}

//free functions:
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}