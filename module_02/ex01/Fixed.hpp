#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>
class Fixed
{
    private:
        int                 value;
        static const int    fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(const int n);
        Fixed(const float f);
        Fixed(const Fixed &fx);
        ~Fixed(void);
        // Overloading of Operators
        void    operator=(const Fixed &fx);
        
        int     getRawBits(void) const;
        int     getFractionalBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;
        int     toIntDecimal(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);
#endif