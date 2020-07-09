#ifndef PARENTHESES_HPP
# define PARENTHESES_HPP

# include "Itoken.hpp"

class Parentheses: public IToken
{
    private:
        bool m_open;
        Parentheses(void);
    public:
        Parentheses(bool);
        Parentheses(const Parentheses&);
        ~Parentheses(void);

        Parentheses& operator=(const Parentheses&);

        int         priority(void) const;
        std::string toString(void) const;
        IToken*     clone(void) const;
        char        getIDChar(void) const;

        bool isOpen(void) const;
};

#endif