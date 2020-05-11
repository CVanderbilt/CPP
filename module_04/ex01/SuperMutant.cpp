#include <iostream>
#include "Enemy.hpp"
#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void):
    Enemy(170, "Super Mutant"){
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant& sm):
    Enemy(170, "Super Mutant"){
    *this = sm;
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant(void){
    std::cout << "Aaargh..." << std::endl;
}

SuperMutant& SuperMutant::operator=(const SuperMutant& s){
    this->type = s.getType();
    this->hit_points = s.getHP();
    return (*this);
}

void SuperMutant::takeDamage(int dmg){
    dmg -= 3;
    if (dmg <= 0)
        return ;
    this->hit_points -= dmg;
    this->hit_points = this->hit_points >= 0 ? this->hit_points : 0;
}