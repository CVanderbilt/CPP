#include "ScavTrap.hpp"
#include <iostream>

const std::string Scavtrap::challenges_list[] = {
    "Stole some candy from those annoying children",
    "Listen this short story i wrote",
    "Help me finish this sudoku",
    "Go shoot some bandits while i figure out how to open the door",
    "Come tomorrow, i cant invent a challenge for you right now"    
};

Scavtrap::Scavtrap(void): hit_points(100), max_hit_points(100), energy_points(50), max_energy_points(50),
                             level (1), name("default_sc4v_tr4p"), melee_damage(20), ranged_damage(15), armor(3){
    std::cout << "(SC4V-TP)Default constructor" << std::endl;
}

Scavtrap::Scavtrap(std::string name): hit_points(100), max_hit_points(100), energy_points(50), max_energy_points(50),
                            level(1), name(name), melee_damage(20), ranged_damage(15), armor(3){
    std::cout << "(SC4V-TP)Named constructor" << std::endl;
}

Scavtrap::Scavtrap(Scavtrap const &ft){
    std::cout << "(SC4V-TP)Copy constructor called" << std::endl;
    *this = ft;
}

Scavtrap::~Scavtrap(void){
    std::cout << "(SC4V-TP)Destructor called" << std::endl;
}

Scavtrap& Scavtrap::operator=(const Scavtrap &ft){
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

    return (*this);
}

void Scavtrap::rangedAttack(std::string const & target){
    std::cout << "SC4V-TP " << name <<  " attacks " << target << " at range, causing " << ranged_damage << " points of damage!" << std::endl;
}

void Scavtrap::meleeAttack(std::string const & target){
    std::cout << "SC4V-TP " << name <<  " attacks " << target << " at melee, causing " << melee_damage << " points of damage!" << std::endl;
}

void Scavtrap::takeDamage(unsigned int amount){
    int int_amount = amount - armor;
    std::cout << name << "takes damage:" << std::endl;
    if (int_amount > 0)
    {
        hit_points -= int_amount;
        if (hit_points < 0)
            hit_points = 0;
        std::cout << int_amount << "(SC4V-TP)(" << amount << ") damage taken, hp left " << hit_points << std::endl; 
    }
    else
        std::cout << "(SC4V-TP)None damage taken" << std::endl;
}

void Scavtrap::beRepaired(unsigned int amount){
    std::cout << "(SC4V-TP) " << name << " repairs itself, hp(" << hit_points << ") + (" << amount << "), total (";  
    hit_points += amount;
    if (hit_points > max_hit_points)
        hit_points = max_hit_points;
    std::cout << hit_points << ")" << std::endl;
}

void Scavtrap::challengeNewcomer(){
    int aux;

    aux = energy_points - 25;
    std::cout << name << " tries to challenge" << std::endl;
    if (aux >= 0){
        energy_points -= 25;
        std::cout << "(SC4V-TP) " << name << " challenges:" << std::endl;
        std::cout << "'I challenge you to " << challenges_list[rand() % 5] << std::endl;
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl; 
}


//get & set
int Scavtrap::getHP(void) const {return (hit_points);}
int Scavtrap::getMaxHP(void) const {return (max_hit_points);}
int Scavtrap::getEnergy(void) const {return (energy_points);}
int Scavtrap::getMaxEnergy(void) const {return (max_energy_points);}
int Scavtrap::getLevel(void) const {return (level);}
int Scavtrap::getRangedDamage(void) const {return (ranged_damage);}
int Scavtrap::getMeleeDamage(void) const {return (melee_damage);}
int Scavtrap::getArmor(void) const {return (armor);}
std::string Scavtrap::getName(void) const {return (name);}