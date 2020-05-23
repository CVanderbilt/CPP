#include <iostream>
#include "Asteroid.hpp"

Asteroid::Asteroid(void){}
Asteroid::Asteroid(const Asteroid& c){*this = c;}
Asteroid::~Asteroid(void){}

Asteroid& Asteroid::operator=(const Asteroid& c){
    (void)c;
    return (*this);
}

std::string Asteroid::beMined(DeepCoreMiner* tool) const
{
    (void)tool;
    return ("Dragonite");
}

std::string Asteroid::beMined(StripMiner* tool) const
{
    (void)tool;
    return ("Flavium");
}

std::string Asteroid::getName(void) const{return ("Asteroid");}