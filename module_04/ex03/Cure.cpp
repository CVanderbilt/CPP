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
    Cure* ret = new Cure;
    *ret = *this;
    return (ret);
}

void Cure::use(ICharacter& target){
    std::cout << "* Cures " << target.getName() << " wounds *" << std::endl;
    this->AMateria::use(target);
}