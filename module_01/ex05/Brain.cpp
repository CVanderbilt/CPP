#include "Brain.hpp"
#include <sstream>
#include <iostream>
#include <iomanip>

Brain::Brain(void): name("noname") {}
Brain::Brain(std::string name): name(name) {}

Brain::~Brain(void){

}

void        Brain::setName(std::string name){
    this->name = name;
}

std::string Brain::identify(void) const
{
    std::stringstream stream;
    stream << std::hex << this;
    std::string result(stream.str());
    return (result);
}