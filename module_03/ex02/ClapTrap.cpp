#include "ClapTrap.hpp"

Claptrap::Claptrap(void): level(1){
    std::cout << "(CP)Default constructor" << std::endl;
}

Claptrap::~Claptrap(void){
    std::cout << "(CP)Destructor called" << std::endl;
}

void Claptrap::operator=(const Claptrap &ft){
    std::cout << "(CP)Asignation operator callled" << std::endl;
    hit_points = ft.getHP();
    max_hit_points = ft.getMaxHP();
    energy_points = ft.getEnergy();
    max_energy_points = ft.getMaxEnergy();
    name = ft.getName();
    level = ft.getLevel();
    ranged_damage = ft.getRangedDamage();
    melee_damage = ft.getMeleeDamage();
    armor = ft.getArmor();
}

void Claptrap::takeDamage(unsigned int amount){
    int int_amount = amount - armor;
    std::cout << "(CP)"<< name << "takes damage:" << std::endl;
    if (int_amount > 0)
    {
        hit_points -= int_amount;
        if (hit_points < 0)
            hit_points = 0;
        std::cout << int_amount << "(" << amount << ") damage taken, hp left " << hit_points << std::endl; 
    }
    else
        std::cout << "None damage taken" << std::endl;
}

void Claptrap::beRepaired(unsigned int amount){
    std::cout << "(CP)" << name << " repairs itself, hp(" << hit_points << ") + (" << amount << "), total (";  
    hit_points += amount;
    if (hit_points > max_hit_points)
        hit_points = max_hit_points;
    std::cout << hit_points << ")" << std::endl;
}

//get & set

int Claptrap::getHP(void) const {return (hit_points);}
int Claptrap::getMaxHP(void) const {return (max_hit_points);}
int Claptrap::getEnergy(void) const {return (energy_points);}
int Claptrap::getMaxEnergy(void) const {return (max_energy_points);}
int Claptrap::getLevel(void) const {return (level);}
int Claptrap::getRangedDamage(void) const {return (ranged_damage);}
int Claptrap::getMeleeDamage(void) const {return (melee_damage);}
int Claptrap::getArmor(void) const {return (armor);}
std::string Claptrap::getName(void) const {return (name);}