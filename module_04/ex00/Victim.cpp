#include "Victim.hpp"
#include <iostream>

//constructors & destructor
Victim::Victim(void){}
Victim::Victim(std::string name): name(name){std::cout << "Some random victim called " << name << " just appeared!" << std::endl;}
Victim::Victim(const Victim &v): name(v.getName()){std::cout << "Some random victim called " << name << " just appeared!" << std::endl;}
Victim::~Victim(void){std::cout << "Victim " << name << " just died for no apparent reason!" << std::endl;}

//overriden operators
std::ostream& operator<<(std::ostream& os, const Victim &v){
    os << "I'm " << v.getName() << " and I like otters!" << std::endl;
    return (os);
}

Victim& Victim::operator=(const Victim &v){
    name = v.getName();
    return (*this);
}

//other
void Victim::getPolymorphed(void) const{
    std::cout << name << " has been turned into a cute little sheep!" << std::endl;
}

//get & set
std::string Victim::getName(void) const{return (name);}
