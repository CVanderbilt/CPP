#include "FragTrap.hpp"
#include <iostream>

const std::string Fragtrap::abilities_list[] = {
    "Kick Him While He's Down",
    "You're... GOING TO LOVE ME!!",
    "I Am Rubber, You Are Glue",
    "Livin' Near the Edge",
    "Tripleclocked"    
};

Fragtrap::Fragtrap(void){
    std::cout << "Default constructor" << std::endl;
    hit_points = 100;
    max_hit_points = 100;
    energy_points = 100;
    max_energy_points = 100;
    melee_damage = 30;
    ranged_damage = 20;
    armor = 5;
    level = 1;
}

Fragtrap::Fragtrap(std::string otherName){
    std::cout << "Named constructor" << std::endl;
    hit_points = 100;
    max_hit_points = 100;
    energy_points = 100;
    max_energy_points = 100;
    melee_damage = 30;
    ranged_damage = 20;
    armor = 5;
    level = 1;
    name = otherName;
}

Fragtrap::Fragtrap(Fragtrap const &ft){
    std::cout << "Copy constructor called" << std::endl;
    *this = ft;
}

Fragtrap::~Fragtrap(void){
    std::cout << "(FR4G-TP)Destructor called" << std::endl;
}

Fragtrap& Fragtrap::operator=(const Fragtrap &ft){
    std::cout << "Asignation operator callled" << std::endl;
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

void Fragtrap::meleeAttack(std::string const &target){
    std::cout << "FR4G-TP" << name << " makes a melee frag attack to " << target << ", dealing " << melee_damage << " damage" << std::endl;
}

void Fragtrap::rangedAttack(std::string const &target){
    std::cout << "FR4G-TP" << name << " makes a melee frag attack to " << target <<", dealing " << ranged_damage << " damage" << std::endl;
}

void Fragtrap::vaulthunter_dot_exe(std::string const &target){
    std::cout << name << " tries vault_hunter_dot_exe" << std::endl;
    if (energy_points >= 25){
        energy_points -= 25;
        std::cout << "vault_hunter_dot_exe activated: " << abilities_list[rand() % 5] << " against " << target << std::endl;
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl;   
}