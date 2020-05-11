#include <iostream>
#include "AssaultTerminator.hpp"


//constructors & destructor
AssaultTerminator::AssaultTerminator(void){std::cout << "* teleports from space *" << std::endl;}
AssaultTerminator::AssaultTerminator(const AssaultTerminator& tm){(void)tm; std::cout << "* teleports from space *" << std::endl;}
AssaultTerminator::~AssaultTerminator(void){std::cout << "I’ll be back..." << std::endl;}

//operators
AssaultTerminator& AssaultTerminator::operator=(const AssaultTerminator& tm){
    (void)tm;
    return (*this);
}

//others
ISpaceMarine* AssaultTerminator::clone(void) const{
    AssaultTerminator *tm = new AssaultTerminator();
    *tm = *this;
    return (tm);
}

void AssaultTerminator::battleCry(void) const{std::cout << "This code is unclean. PURIFY IT!" << std::endl;}
void AssaultTerminator::meleeAttack(void) const{std::cout << "* attacks with chainfists *" << std::endl;}
void AssaultTerminator::rangedAttack(void) const{std::cout << "* does nothing *" << std::endl;}
//get & set