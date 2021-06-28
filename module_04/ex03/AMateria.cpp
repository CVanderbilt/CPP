#include "AMateria.hpp"

AMateria::AMateria(void){}
AMateria::AMateria(std::string const & type): type(type), _xp(0){}
AMateria::AMateria(const AMateria& m){*this = m;}
AMateria::~AMateria(void){}

AMateria& AMateria::operator=(const AMateria& m){
    this->type = m.getType();
    this->_xp = m.getXP();
    return (*this);
}

void AMateria::use(ICharacter& target){
	(void)target;
    this->_xp += 10;
}

unsigned int AMateria::getXP(void) const{return (this->_xp);}
std::string const& AMateria::getType(void) const{return (this->type);}
void AMateria::setXp(int xp){this->_xp = xp;}