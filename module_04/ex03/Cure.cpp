#include "Cure.hpp"
#include <iomanip>

Cure::Cure(void): AMateria("cure"){}
Cure::Cure(const Cure& i): AMateria("cure"){*this = i;}
Cure::~Cure(void){}

Cure& Cure::operator=(const Cure& i){
    this->setXp(i.getXP());
    return (*this);
}

AMateria* Cure::clone() const{
    //std::cout << "Intenta clonar Cure: ";
    Cure* ret = new Cure;
    *ret = *this;
    //std::cout << ret << std::endl;
    return (ret);
}

void Cure::use(ICharacter& target){
    std::cout << "* Cures " << target.getName() << " wounds *" << std::endl;
    this->AMateria::use(target);
    //std::cout << "xp: " << this->getXP() << std::endl;
}