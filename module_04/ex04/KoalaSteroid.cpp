#include <iostream>
#include "KoalaSteroid.hpp"

KoalaSteroid::KoalaSteroid(void){}
KoalaSteroid::KoalaSteroid(const KoalaSteroid& c){*this = c;}
KoalaSteroid::~KoalaSteroid(void){}

KoalaSteroid& KoalaSteroid::operator=(const KoalaSteroid& c){
    (void)c;
    return (*this);
}

std::string KoalaSteroid::beMined(DeepCoreMiner* tool) const
{
    (void)tool;
    return ("Meium");
}

std::string KoalaSteroid::beMined(StripMiner* tool) const
{
    (void)tool;
    return ("Tartarite");
}
std::string KoalaSteroid::getName(void) const{return ("KoalaSteroid");}