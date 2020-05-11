#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
    private:
        int                 value;
        static const int    fractional_bits = 8;
        static const int    fraction_mask = 255; //8 rightmost bits set
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &fx);
        ~Fixed(void);
        // Overloading of Operators
        void    operator=(const Fixed &fx);
        bool    operator==(const Fixed& fx);
        bool    operator<(const Fixed& fx);
        bool    operator>(const Fixed& fx);
        bool    operator<=(const Fixed& fx);
        bool    operator>=(const Fixed& fx);
        bool    operator!=(const Fixed& fx);

        Fixed    operator+(const Fixed &fx);
        Fixed    operator-(const Fixed &fx);
        Fixed    operator/(const Fixed &fx);
        Fixed    operator*(const Fixed &fx);

        Fixed operator++();
        Fixed operator++(int);
        Fixed operator--();
        Fixed operator--(int);

        int     getRawBits(void) const;
        static int     getFractionalBits(void);
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        int     toIntDecimal(void) const;
};

std::ostream&   operator<<(std::ostream& os, const Fixed& obj);

Fixed    operator+(const Fixed &fx1, Fixed &fx2);
Fixed    operator-(const Fixed &fx, Fixed &fx2);
Fixed    operator/(const Fixed &fx, Fixed &fx2);
Fixed    operator*(const Fixed &fx, Fixed &fx2);

Fixed    &min(Fixed &fx1, Fixed &fx2);
Fixed    const &min(Fixed const &fx1, Fixed const &fx2);
Fixed    &max(Fixed &fx1, Fixed &fx2);
Fixed    const &max(Fixed const &fx1, Fixed const &fx2);
#endif