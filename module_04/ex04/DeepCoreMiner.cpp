#include "DeepCoreMiner.hpp"
#include <iostream>

DeepCoreMiner::DeepCoreMiner(void){}
DeepCoreMiner::DeepCoreMiner(const DeepCoreMiner& d){*this = d;}
DeepCoreMiner::~DeepCoreMiner(void){}

DeepCoreMiner& DeepCoreMiner::operator=(const DeepCoreMiner& d){
    (void)d;
    return (*this);
}

void DeepCoreMiner::mine(IAsteroid* a)
{
    if (a)
        std::cout << "* mining deep... got " << a->beMined(this) << "! *" << std::endl;
}