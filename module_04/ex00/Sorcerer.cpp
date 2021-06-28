#include "Sorcerer.hpp"
#include <iostream>

//constructors & destructor
Sorcerer::Sorcerer(void){};
Sorcerer::Sorcerer(std::string name, std::string title): name(name), title (title){std::cout << name << ", " << title << ", is born!" << std::endl;}
Sorcerer::~Sorcerer(void){std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl; }
Sorcerer::Sorcerer(const Sorcerer& s){
    *this = s;
    std::cout << name << ", " << title << ", is born!" << std::endl;
}

//overriden operators
std::ostream& operator<<(std::ostream& os, const Sorcerer& s)
{
    os << "I am " << s.getName() << ", " << s.getTitle() << ", and I like ponies!" << std::endl;
    return os;
}

Sorcerer& Sorcerer::operator=(const Sorcerer& s){
    this->name = s.getName();
    this->title = s.getTitle();
    return (*this);
}

//other
void Sorcerer::polymorph(Victim const &v) const{
    v.getPolymorphed();
}

//get & set
std::string Sorcerer::getName(void) const{return (name);}
std::string Sorcerer::getTitle(void) const{return (title);}

