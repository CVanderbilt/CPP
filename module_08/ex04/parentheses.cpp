#include "parentheses.hpp"
#include <sstream>

//Constructors & destructor
Parentheses::Parentheses(bool b): m_open(b){}
Parentheses::Parentheses(const Parentheses& n){*this = n;}
Parentheses::~Parentheses(void){}

//Operators
Parentheses& Parentheses::operator=(const Parentheses& n){
    this->m_open= n.isOpen();
    return (*this);
}

//Other
std::string Parentheses::toString(void) const
{
    std::stringstream s;

    s << (this->m_open ? "ParOpen" : "ParClose");
    return (s.str());
}

int         Parentheses::priority(void) const
{
    if (this->m_open)
        return (0);
    return (3);
}

IToken*     Parentheses::clone(void) const
{
    return (new Parentheses(*this));
}

char        Parentheses::getIDChar(void) const
{
    return (this->m_open ? '(' : ')');
}

//Get & set
bool Parentheses::isOpen(void) const{return (this->m_open);}


