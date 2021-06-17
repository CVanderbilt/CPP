#include <iostream>
#include "AsteroKreog.hpp"

AsteroKreog::AsteroKreog(void){}
AsteroKreog::AsteroKreog(const AsteroKreog& c){*this = c;}
AsteroKreog::~AsteroKreog(void){}

AsteroKreog& AsteroKreog::operator=(const AsteroKreog& c){
    (void)c;
    return (*this);
}

std::string AsteroKreog::beMined(DeepCoreMiner* tool) const
{
    (void)tool;
    return ("Dragonite");
}

std::string AsteroKreog::beMined(StripMiner* tool) const
{
    (void)tool;
    return ("Flavium");
}

std::string AsteroKreog::getName(void) const{return ("AsteroKreog");}