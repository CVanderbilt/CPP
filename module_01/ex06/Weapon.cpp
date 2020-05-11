#include "Weapon.hpp"

Weapon::Weapon(void): type("no weapon"){}
Weapon::Weapon(std::string type): type(type){}

void        Weapon::setType(std::string type){
    this->type = type;
}

std::string Weapon::getType(void){
    return (this->type);
}