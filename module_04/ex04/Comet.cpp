#include <iostream>
#include "Comet.hpp"

Comet::Comet(void){}
Comet::Comet(const Comet& c){*this = c;}
Comet::~Comet(void){}

Comet& Comet::operator=(const Comet& c){
    (void)c;
    return (*this);
}

std::string Comet::beMined(DeepCoreMiner* tool) const
{
    (void)tool;
    return ("Meium");
}

std::string Comet::beMined(StripMiner* tool) const
{
    (void)tool;
    return ("Tartarite");
}
std::string Comet::getName(void) const{return ("Comet");}