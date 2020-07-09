#ifndef ITOKEN_HPP
# define ITOKEN_HPP
# include <iostream>

class IToken
{
    public:
        virtual ~IToken(void){};

        virtual int priority(void) const = 0;
        virtual std::string toString(void) const = 0;
        virtual IToken* clone() const = 0;
        virtual char getIDChar(void) const = 0;
};

#endif