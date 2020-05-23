#include "StripMiner.hpp"
#include <iostream>

StripMiner::StripMiner(void){}
StripMiner::StripMiner(const StripMiner& d){*this = d;}
StripMiner::~StripMiner(void){}

StripMiner& StripMiner::operator=(const StripMiner& d){
    (void)d;
    return (*this);
}

void StripMiner::mine(IAsteroid* a)
{
    if (a)
        std::cout << "* strip minin... got " << a->beMined(this) << "! *" << std::endl;
}