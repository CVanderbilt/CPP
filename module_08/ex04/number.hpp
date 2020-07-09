#ifndef NUMBER_HPP
# define NUMBER_HPP

# include "Itoken.hpp"

class Number: public IToken
{
    private:
        int m_value;
    public:
        Number(void);
        Number(int);
        Number(const Number&);
        ~Number(void);

        Number& operator=(const Number&);

        std::string toString(void) const;
        int         priority(void) const;
        IToken*     clone(void) const;
        char        getIDChar(void) const;

        int getValue(void) const;

        Number& operator+(const Number&);
        Number& operator-(const Number&);
        Number& operator*(const Number&);
        Number& operator/(const Number&);
};

#endif