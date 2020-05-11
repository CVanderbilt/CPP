#include "AWeapon.hpp"
#include "PowerFist.hpp"

PowerFist::PowerFist(void):
    AWeapon("Power Fist", 8, 50)
    {}
PowerFist::PowerFist(const PowerFist& p):
    AWeapon("Power Fist", 8, 50){
    *this = p;
}
PowerFist::~PowerFist(void){}

PowerFist& PowerFist::operator=(const PowerFist& p){
    this->name = p.getName();
    this->damage = p.getDamage();
    this->cost = p.getAPCost();
    return (*this);
}

void PowerFist::attack(void) const{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}