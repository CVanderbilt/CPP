#include <iostream>
#include "Human.hpp"
#include "Brain.hpp"

Human::Human(void): name("John"), lastname("Doe"){}
Human::Human(std::string name): name(name), lastname("Doe"){}
Human::Human(std::string name, std::string lastname): name(name), lastname(lastname){}

Human::~Human(void){

}

std::string Human::identify(void) const{
    return (this->brain.identify());
}

void        Human::setName(std::string name){
    this->name = name;
}

void        Human::setLastName(std::string lastname){
    this->lastname = lastname;
}

const Brain &Human::getBrain(void){
    return (this->brain);
} 