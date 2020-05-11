#include <iostream>
#include "TacticalMarine.hpp"


//constructors & destructor
TacticalMarine::TacticalMarine(void){std::cout << "Tactical Marine ready for battle" << std::endl;}
TacticalMarine::TacticalMarine(const TacticalMarine& tm){(void)tm; std::cout << "Tactical Marine ready for battle" << std::endl;}
TacticalMarine::~TacticalMarine(void){std::cout << "Aaargh..." << std::endl;}

//operators
TacticalMarine& TacticalMarine::operator=(const TacticalMarine& tm){
    (void)tm;
    return (*this);
}

//others
ISpaceMarine* TacticalMarine::clone(void) const{
    TacticalMarine *tm = new TacticalMarine();
    *tm = *this;
    return (tm);
}

void TacticalMarine::battleCry(void) const{std::cout << "For the holy PLOT!" << std::endl;}
void TacticalMarine::meleeAttack(void) const{std::cout << "* attacks with a chainsword *" << std::endl;}
void TacticalMarine::rangedAttack(void) const{std::cout << "* attacks with a bolter *" << std::endl;}
//get & set