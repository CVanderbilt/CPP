#include "number.hpp"
#include <sstream>

//Constructors & destructor
Number::Number(void): m_value(0){}
Number::Number(int n): m_value(n){}
Number::Number(const Number& n){*this = n;}
Number::~Number(void){}

//Operators
Number& Number::operator=(const Number& n){
    this->m_value = n.getValue();
    return (*this);
}

Number& Number::operator*(const Number& n){
    this->m_value *= n.getValue();
    return (*this);
}

Number& Number::operator/(const Number& n){
    this->m_value /= n.getValue();
    return (*this);
}

Number& Number::operator+(const Number& n){
    this->m_value += n.getValue();
    return (*this);
}

Number& Number::operator-(const Number& n){
    this->m_value -= n.getValue();
    return (*this);
}
//Other
std::string Number::toString(void) const
{
    std::stringstream s;

    s << "Num(" << this->m_value << ")";
    return (s.str());
}

int Number::priority(void) const
{
    return (-1);
}

IToken* Number::clone(void) const
{
    return (new Number(*this));
}

char Number::getIDChar(void) const
{
    return ('n');
}

//Get & set
int Number::getValue(void) const {return (this->m_value);}