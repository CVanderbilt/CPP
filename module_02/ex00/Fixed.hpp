#ifndef FIXED_HPP
# define FIXED_HPP
class Fixed
{
    private:
        int                 value;
        static const int    fractional_bits = 8;
    public:
        Fixed(void);
        Fixed(Fixed &fx);
        ~Fixed(void);
        // Overloading of Assignment Operator
        void    operator=(const Fixed &fx);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
};
#endif