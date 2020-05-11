#include "SuperTrap.hpp"
#include <iostream>

Supertrap::Supertrap(){

}

Supertrap::Supertrap(std::string otherName): Ninjatrap(otherName), Fragtrap(otherName)
{
    std::cout << "Creating SuperTrap" << std::endl;
    std::cout << "temporal traps:" << std::endl;
    Ninjatrap ninja_tmp;
    Fragtrap frag_tmp;
    this->hit_points = frag_tmp.getHP();
    this->max_hit_points = frag_tmp.getMaxHP();
    this->energy_points = ninja_tmp.getEnergy();
    this->max_energy_points = ninja_tmp.getMaxEnergy();
    this->name = otherName;
    this->melee_damage = ninja_tmp.getMeleeDamage();
    this->ranged_damage = frag_tmp.getRangedDamage();
    this->armor = frag_tmp.getArmor();
    std::cout << "SuperTrap created" << std::endl << std::endl;
}

Supertrap::~Supertrap(void){

}

void Supertrap::meleeAttack(std::string target){
    this->Ninjatrap::meleeAttack(target);
}

void Supertrap::rangedAttack(std::string target){
    this->Fragtrap::rangedAttack(target);
}