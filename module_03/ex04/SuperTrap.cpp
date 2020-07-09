#include "SuperTrap.hpp"
#include <iostream>

Supertrap::Supertrap(){
    std::cout << "Creating SuperTrap" << std::endl;
    std::cout << "temporal traps:" << std::endl;
    Ninjatrap ninja_tmp;
    Fragtrap frag_tmp;
    this->hit_points = frag_tmp.getHP();
    this->max_hit_points = frag_tmp.getMaxHP();
    this->energy_points = ninja_tmp.getEnergy();
    this->max_energy_points = ninja_tmp.getMaxEnergy();
    this->name = "Default_supertrap";
    this->melee_damage = ninja_tmp.getMeleeDamage();
    this->ranged_damage = frag_tmp.getRangedDamage();
    this->armor = frag_tmp.getArmor();
    std::cout << "SuperTrap created" << std::endl << std::endl;
}

Supertrap::Supertrap(std::string otherName): Fragtrap(otherName), Ninjatrap(otherName)
{
    this->hit_points = Fragtrap::getInitialHP();
    this->max_hit_points = Fragtrap::getInitialMaxHP();
    this->energy_points = Ninjatrap::getInitialEnergy();
    this->max_energy_points = Ninjatrap::getInitialMaxEnergy();
    this->name = otherName;
    this->melee_damage = Ninjatrap::getInitialMeleeDmg();
    this->ranged_damage = Fragtrap::getInitialRangedDmg();
    this->armor = Fragtrap::getInitialArmor();
    std::cout << "SuperTrap created" << std::endl << std::endl;
}

Supertrap::Supertrap(const Supertrap& sp){
    *this = sp;
}

Supertrap::~Supertrap(void){
    std::cout << "Supertrap destructor" << std::endl;
}

Supertrap& Supertrap::operator=(const Supertrap& sp)
{
    this->hit_points = sp.getHP();
    this->max_hit_points = sp.getMaxHP();
    this->energy_points = sp.getEnergy();
    this->max_energy_points = sp.getMaxEnergy();
    this->name = sp.getName();
    this->melee_damage = sp.getMeleeDamage();
    this->ranged_damage = sp.getRangedDamage();
    this->armor = sp.getArmor();

    return (*this);
}

void Supertrap::meleeAttack(std::string target){
    this->Ninjatrap::meleeAttack(target);
}

void Supertrap::rangedAttack(std::string target){
    this->Fragtrap::rangedAttack(target);
}