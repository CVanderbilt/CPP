#include <iostream>
#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void):
    Enemy(80, "RadScorpion"){
        std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion& r):
    Enemy(80, "RadScorpion"){
		(void)r;
        std::cout << "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion(void){
    std::cout << "* SPROTCH *" << std::endl;
}