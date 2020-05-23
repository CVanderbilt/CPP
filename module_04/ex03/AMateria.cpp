#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _xp(0), type(type){}
AMateria::AMateria(const AMateria& m){*this = m;}
AMateria::~AMateria(void){}

AMateria& AMateria::operator=(const AMateria& m){
    this->type = m.getType();
    this->_xp = m.getXP();
    return (*this);
}

void AMateria::use(ICharacter& target){
    std::cout << "AMateria: " << this->type << " used" << std::endl;
    //std::cout << "xp: " << this->_xp << "; ";
    this->_xp++;
    //std::cout << "xp: " << this->_xp << "; ";
}

unsigned int AMateria::getXP(void) const{return (this->_xp);}
std::string const& AMateria::getType(void) const{return (this->type);}
void AMateria::setXp(int xp){this->_xp = xp;}