#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void):
    Enemy(80, "RadScorpion"){
        std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& r):
    Enemy(80, "RadScorpion"){
		*this = r;
        std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void){
    std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion& RadScorpion::operator=(const RadScorpion& s){
    this->type = s.getType();
    this->hit_points = s.getHP();
    return (*this);
}