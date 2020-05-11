#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//constructors & destructor:
Fixed::Fixed(void): value(0){}
Fixed::Fixed(const Fixed &fx): value(fx.value){}
Fixed::Fixed(float f){value = roundf(f * (1 << fractional_bits));}
Fixed::Fixed(int i){value = i << fractional_bits;}
Fixed::~Fixed(void){}

// Overloading Operators
void    Fixed::operator=(const Fixed &fx){
    value = fx.getRawBits();
}

//get & set
int     Fixed::getRawBits(void) const{
    return (value);
}

int     Fixed::getFractionalBits(void){
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

int     Fixed::toIntDecimal(void) const
{
    return (value & fraction_mask);
}

float   Fixed::toFloat(void) const
{
    return ((double)value / (double)(1 << fractional_bits));
}

Fixed   &min(Fixed &fx1, Fixed &fx2){
    if (fx1 <= fx2)
        return (fx1);
    return (fx2);
}

Fixed   const &min(Fixed const &fx1, Fixed const &fx2){
    if (fx1.getRawBits() <= fx2.getRawBits())
        return (fx1);
    return (fx2);
}

Fixed   &max(Fixed &fx1, Fixed &fx2){
    if (fx1 >= fx2)
        return (fx1);
    return (fx2);
}

Fixed   const &max(Fixed const &fx1, Fixed const &fx2){
    if (fx1.getRawBits() >= fx2.getRawBits())
        return (fx1);
    return (fx2);
}
/*
Fixed   &Fixed::min(Fixed &fx1, Fixed &fx2){
    if (fx1 <= fx2)
        return (fx1);
    return (fx2);
}

Fixed   const &Fixed::min(Fixed const &fx1, Fixed const &fx2){
    return (min(fx1, fx2));
}

Fixed   &Fixed::max(Fixed &fx1, Fixed &fx2){
    if (fx1.getRawBits() >= fx2.getRawBits())
        return (fx1);
    return (fx2);
}

Fixed   const &Fixed::max(Fixed const &fx1, Fixed const &fx2){
    if (fx1.getRawBits() >= fx2.getRawBits())
        return (fx1);
    return (fx2);
}*/

//overriden operators:
std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}

bool    Fixed::operator==(const Fixed& fx){return (value == fx.getRawBits());}
bool    Fixed::operator<=(const Fixed& fx){return (value <= fx.getRawBits());}
bool    Fixed::operator>=(const Fixed& fx){return (value >= fx.getRawBits());}
bool    Fixed::operator!=(const Fixed& fx){return (value != fx.getRawBits());}
bool    Fixed::operator<(const Fixed& fx){return (value < fx.getRawBits());}
bool    Fixed::operator>(const Fixed& fx){return (value > fx.getRawBits());}

Fixed    Fixed::operator+(const Fixed &fx){
    value = value + fx.getRawBits();
    return (*this);
}
Fixed    Fixed::operator-(const Fixed &fx){

    value = value - fx.getRawBits();
    return (*this);
}
Fixed    Fixed::operator/(const Fixed &fx){
    long long ret;

    ret = value << Fixed::getFractionalBits();
    value = ret / fx.getRawBits(); 
    return (*this);
}
Fixed    Fixed::operator*(const Fixed &fx){
    long long ret;

    ret = (value * fx.getRawBits()) >> Fixed::getFractionalBits();
    value = ret;
    return (*this);
}

Fixed        Fixed::operator++(){
    value += 1;
    return (*this);
}
Fixed        Fixed::operator++(int){
    Fixed tmp(*this);
    operator++();
    return (tmp);
}
Fixed        Fixed::operator--(){
    value -= 1;
    return (*this);
}
Fixed        Fixed::operator--(int){
    Fixed tmp(*this);
    operator--();
    return (tmp);
}