#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): name("noname"), type("basic"){}
Zombie::Zombie(std::string name): name(name){}
Zombie::Zombie(std::string name, std::string type): name(name), type(type){}

Zombie::~Zombie(void){
    std::cout << this->type << " zombie named: " << this->name << " destroyed" << std::endl;
}

void    Zombie::setName(std::string name){
    this->name = name;
}

void    Zombie::setType(std::string type){
    this->type = type;
}

void    Zombie::announce(void){
   std::cout << "<" << this->name << " (" << this->type << ")> "<< " Braiiiiiiinnnssss..." << std::endl;
}