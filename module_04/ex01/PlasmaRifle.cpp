#include "AWeapon.hpp"
#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void):
    AWeapon("Plasma Rifle", 5, 21)
    {}
PlasmaRifle::PlasmaRifle(const PlasmaRifle& p):
    AWeapon("Plasma Rifle", 5, 21){
    *this = p;
}
PlasmaRifle::~PlasmaRifle(void){}

PlasmaRifle& PlasmaRifle::operator=(const PlasmaRifle& p){
    this->name = p.getName();
    this->damage = p.getDamage();
    this->cost = p.getAPCost();
    return (*this);
}

void PlasmaRifle::attack(void) const{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}