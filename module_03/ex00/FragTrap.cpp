#include "FragTrap.hpp"
#include <iostream>

const std::string Fragtrap::abilities_list[] = {
    "Kick Him While He's Down",
    "You're... GOING TO LOVE ME!!",
    "I Am Rubber, You Are Glue",
    "Livin' Near the Edge",
    "Tripleclocked"    
};

Fragtrap::Fragtrap(void): hit_points(100), max_hit_points(100), energy_points(100), max_energy_points(100),
                            melee_damage(30), ranged_damage(20), armor(5), level(1), name("default_fr4g_tr4p"){
    std::cout << "Default constructor" << std::endl;
}

Fragtrap::Fragtrap(std::string name): hit_points(100), max_hit_points(100), energy_points(100), max_energy_points(100),
                            melee_damage(30), ranged_damage(20), armor(5), level(1), name(name){
    std::cout << "Named constructor" << std::endl;
}

Fragtrap::Fragtrap(Fragtrap const &ft){
    std::cout << "Copy constructor called" << std::endl;
    *this = ft;
}

Fragtrap::~Fragtrap(void){
    std::cout << "Destructor called" << std::endl;
}

void Fragtrap::operator=(const Fragtrap &ft){
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
}

void Fragtrap::rangedAttack(std::string const & target){
    std::cout << "FR4G-TP " << name <<  " attacks " << target << " at range, causing " << ranged_damage << " points of damage!" << std::endl;
}

void Fragtrap::meleeAttack(std::string const & target){
    std::cout << "FR4G-TP " << name <<  " attacks " << target << " at melee, causing " << melee_damage << " points of damage!" << std::endl;
}

void Fragtrap::takeDamage(unsigned int amount){
    int int_amount = amount - armor;
    std::cout << name << "takes damage:" << std::endl;
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

void Fragtrap::beRepaired(unsigned int amount){
    std::cout << name << " repairs itself, hp(" << hit_points << ") + (" << amount << "), total (";  
    hit_points += amount;
    if (hit_points > max_hit_points)
        hit_points = max_hit_points;
    std::cout << hit_points << ")" << std::endl;
}

void Fragtrap::vaulthunter_dot_exe(std::string const &target){
    int aux;

    aux = energy_points - 25;
    std::cout << name << " tries vault_hunter_dot_exe" << std::endl;
    if (aux >= 0){
        energy_points -= 25;
        std::cout << "vault_hunter_dot_exe activated: " << abilities_list[rand() % 5] << " against " << target << std::endl;
    }
    else
        std::cout << "Not enought energy points, have " << energy_points << " need: 25" << std::endl;
    
}


//get & set
int Fragtrap::getHP(void) const {return (hit_points);}
int Fragtrap::getMaxHP(void) const {return (max_hit_points);}
int Fragtrap::getEnergy(void) const {return (energy_points);}
int Fragtrap::getMaxEnergy(void) const {return (max_energy_points);}
int Fragtrap::getLevel(void) const {return (level);}
int Fragtrap::getRangedDamage(void) const {return (ranged_damage);}
int Fragtrap::getMeleeDamage(void) const {return (melee_damage);}
int Fragtrap::getArmor(void) const {return (armor);}
std::string Fragtrap::getName(void) const {return (name);}