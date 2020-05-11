#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

const std::string Scavtrap::challenges_list[] = {
    "Stole some candy from those annoying children",
    "Listen this short story i wrote",
    "Help me finish this sudoku",
    "Go shoot some bandits while i figure out how to open the door",
    "Come tomorrow, i cant invent a challenge for you right now"    
};

Scavtrap::Scavtrap(void){
    std::cout << "(SC4V-TP)Default constructor" << std::endl;
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50;
    this->max_energy_points = 50;
    this->melee_damage = 20;
    this->ranged_damage = 15;
    this->armor = 3;
    this->level = 1;
}

Scavtrap::Scavtrap(std::string otherName){
    std::cout << "(SC4V-TP)Named constructor" << std::endl;
    this->name = otherName;
    this->hit_points = 100;
    this->max_hit_points = 100;
    this->energy_points = 50;
    this->max_energy_points = 50;
    this->melee_damage = 20;
    this->ranged_damage = 15;
    this->armor = 3;
    this->level = 1;
}

Scavtrap::Scavtrap(Scavtrap const &ft){
    std::cout << "(SC4V-TP)Copy constructor called" << std::endl;
    *this = ft;
}

Scavtrap::~Scavtrap(void){
    std::cout << "(SC4V-TP)Destructor called" << std::endl;
}

void Scavtrap::operator=(const Scavtrap &ft){
    std::cout << "(SC4V-TP)Asignation operator callled" << std::endl;
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

void Scavtrap::meleeAttack(std::string const &target){
    std::cout << name << " makes a meleee ninja attack, dealing " << melee_damage << " damage" << std::endl;
}

void Scavtrap::rangedAttack(std::string const &target){
    std::cout << name << " makes a meleee ninja attack, dealing " << ranged_damage << " damage" << std::endl;
}

void Scavtrap::challengeNewcomer(){
    int aux;

    aux = energy_points - 25;
    std::cout << name << " tries to challenge" << std::endl;
    if (aux >= 0){
        energy_points -= 25;
        std::cout << "(SC4V-TP) " << name << " challenges:" << std::endl;
        std::cout << "'I challenge you to" << challenges_list[rand() % 5] << std::endl;
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl; 
}