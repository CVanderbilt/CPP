#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

Ninjatrap::Ninjatrap(void){
    std::cout << "(NINJA-TP)Default constructor" << std::endl;
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120;
    this->max_energy_points = 120;
    this->melee_damage = 60;
    this->ranged_damage = 5;
    this->armor = 0;
    this->level = 1;
}

Ninjatrap::Ninjatrap(std::string otherName){
    std::cout << "(NINJA-TP)Named constructor" << std::endl;
    this->name = otherName;
    this->hit_points = 60;
    this->max_hit_points = 60;
    this->energy_points = 120;
    this->max_energy_points = 120;
    this->melee_damage = 60;
    this->ranged_damage = 5;
    this->armor = 0;
    this->level = 1;
}

Ninjatrap::Ninjatrap(Ninjatrap const &ft){
    std::cout << "(NINJA-TP)Copy constructor called" << std::endl;
    *this = ft;
}

Ninjatrap::~Ninjatrap(void){
    std::cout << "(NINJA-TP)Destructor called" << std::endl;
}

Ninjatrap& Ninjatrap::operator=(const Ninjatrap &ft){
    std::cout << "(NINJA-TP)Asignation operator callled" << std::endl;
    hit_points = ft.getHP();
    max_hit_points = ft.getMaxHP();
    energy_points = ft.getEnergy();
    max_energy_points = ft.getMaxEnergy();
    name = ft.getName();
    level = ft.getLevel();
    ranged_damage = ft.getRangedDamage();
    melee_damage = ft.getMeleeDamage();
    armor = ft.getArmor();

    return (*this);
}

void Ninjatrap::meleeAttack(std::string const &target){
    std::cout << "NINJA-TP" << name << " makes a melee ninja attack to " << target << ", dealing " << melee_damage << " damage" << std::endl;
}

void Ninjatrap::rangedAttack(std::string const &target){
    std::cout << "NINJA-TP" << name << " makes a ranged ninja attack to " << target <<", dealing " << ranged_damage << " damage" << std::endl;
}

void Ninjatrap::ninjaShoebox(Claptrap& cp)
{
    std::cout << name << "tries ninja shoebox ability" << std::endl;
    if (energy_points >= 25){
        energy_points -= 25;
        std::cout << name << " ninja steals ability from " << cp.getName() << std::endl;
        std::cout << "It does nothing as Claptrap doesnt do anything ¯\\_(ツ)_/¯" << std::endl;
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl; 
}

void Ninjatrap::ninjaShoebox(Fragtrap &ft){
    std::cout << name << "tries ninja shoebox ability" << std::endl;
    if (energy_points >= 25){
        energy_points -= 25;
        std::cout << name << " ninja steals ability from " << ft.getName() << std::endl;
        ft.vaulthunter_dot_exe(ft.getName());
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl; 
}

void Ninjatrap::ninjaShoebox(Scavtrap &st){
    int aux;

    aux = energy_points - 25;
    std::cout << name << " tries ninja shoebox ability" << std::endl;
    if (aux >= 0){
        energy_points -= 25;
        std::cout << name << " ninja steals ability from " << st.getName() << " " << energy_points << " points left" << std::endl;
        st.challengeNewcomer();
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl; 
}

void Ninjatrap::ninjaShoebox(Ninjatrap &nt){
    std::cout << name << "tries ninja shoebox ability" << std::endl;
    std::cout << nt.getName() << " unafected ninjas are inmune to ninja abilities" << std::endl;
}