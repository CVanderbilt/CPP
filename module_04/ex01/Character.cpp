#include <iostream>
#include "Character.hpp"
#include "AWeapon.hpp"
#include "Enemy.hpp"

//constructors & destructor
Character::Character(void){}
Character::Character(std::string const &name): name(name), action_points(40), w_ptr(0){}
Character::Character(const Character& c){
    *this = c;
}
Character::~Character(void){}

//operators
Character& Character::operator=(const Character& c){
    this->name = c.getName();
    this->action_points = c.getActionPoints();
    this->w_ptr = c.getWeapon();
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Character& c){
    os << c.getName() << " has " << c.getActionPoints() << " AP and ";
    if (c.getWeapon())
        os << "wields a " << c.getWeapon()->getName() << std::endl;
    else
        os << "is unarmed" << std::endl;
    return (os);
}

//others
void Character::recoverAP(void){
    this->action_points += 10;
    if (this->action_points > 40)
        this->action_points = 40;
}

void Character::equip(AWeapon* w){
    this->w_ptr = w;
}

void Character::attack(Enemy *e){
    //"NAME attacks ENEMY_TYPE with a WEAPON_NAME"
    if (this->w_ptr)
    {
        int aux = this->action_points - this->w_ptr->getAPCost();
        if (aux < 0)
            return ;
        this->action_points = aux > 0 ? aux : 0; 
        std::cout << this->name << " attacks " << e->getType() << " with a " << this->w_ptr->getName() << std::endl;
        this->w_ptr->attack();
        e->takeDamage(this->w_ptr->getDamage());
        if (e->getHP() <= 0)
            delete (e);
    }
}

//get & set

std::string const   &Character::getName(void) const{return (this->name);}
int                 Character::getActionPoints(void) const{return (this->action_points);}
AWeapon             *Character::getWeapon(void) const{return (this->w_ptr);}
