#include <iostream>
#include "Peon.hpp"

Peon::Peon(void): Victim("nameless"){}
Peon::Peon(std::string name): Victim(name){std::cout << "Zog zog." << std::endl;}
Peon::Peon(const Peon &p): Victim(p){std::cout << "Zog zog." << std::endl;}
Peon::~Peon(void){std::cout << "Bleuark..." << std::endl;}

Peon& Peon::operator=(const Peon& p){
    name = p.getName();
    return (*this);
}

void Peon::getPolymorphed(void) const{
    std::cout << name << " has been turned into a pink pony!" << std::endl;
}