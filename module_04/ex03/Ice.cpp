#include "Ice.hpp"
#include <iomanip>

Ice::Ice(void): AMateria("ice"){}
Ice::Ice(const Ice& i): AMateria("ice"){*this = i;}
Ice::~Ice(void){}

Ice& Ice::operator=(const Ice& i){
    this->setXp(i.getXP());
    return (*this);
}

AMateria* Ice::clone() const{
    //std::cout << "Intenta clonar ice";
    Ice* ret = new Ice;
    *ret = *this;
    //std::cout << ret << std::endl;
    return (ret);
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    this->AMateria::use(target);
    //std::cout << "xp: " << this->getXP() << std::endl;
}