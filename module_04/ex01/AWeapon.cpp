#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(std::string const & name, int apcost, int damage): name(name), damage(damage), cost(apcost){}
AWeapon::AWeapon(const AWeapon& w){*this = w;}
AWeapon::~AWeapon(void){}

AWeapon& AWeapon::operator=(const AWeapon& w){
    this->name = w.getName();
    this->damage = w.getDamage();
    this->cost = w.getAPCost();
    return (*this);
}

std::string const   &AWeapon::getName(void) const{return (this->name);}
int                 AWeapon::getAPCost(void) const{return (this->cost);}
int                 AWeapon::getDamage(void) const{return (this->damage);}