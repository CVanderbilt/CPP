#include "operand.hpp"
#include <sstream>
#define ISOPERAND(x) (x == '+' || x == '-' || x == '*' || x == '/') 

//Constructors & destructor
Operand::Operand(const char c){
    //if (ISOPERAND(c))
    if (ISOPERAND(c))
        this->m_op = c;
    else
        this->m_op = '+';
}
Operand::Operand(const Operand& o){*this = o;}
Operand::~Operand(void){}

//Operators
Operand& Operand::operator=(const Operand& n){
    this->m_op = n.getIDChar();
    return (*this);
}

//Other
std::string Operand::toString(void) const
{
    std::stringstream s;

    s << "Op(" << this->m_op << ")";
    return (s.str());
}

int         Operand::priority(void) const
{
    if (this->m_op == '*' || this->m_op == '/')
        return (2);
    return (1);
}

IToken*     Operand::clone(void) const
{
    return (new Operand(*this));
}

char        Operand::getIDChar(void) const
{
    return (this->m_op);
}
