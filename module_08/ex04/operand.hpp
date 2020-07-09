#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "Itoken.hpp"

class Operand: public IToken
{
    private:
        Operand(void);
        char m_op;
    public:
        Operand(char);
        Operand(const Operand&);
        ~Operand(void);

        Operand& operator=(const Operand&);

        int         priority(void) const;
        std::string toString(void) const;
        IToken*     clone(void) const;
        char        getIDChar(void) const;
};

#endif