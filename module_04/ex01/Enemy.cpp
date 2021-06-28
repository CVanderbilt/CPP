#include <iostream>
#include "Enemy.hpp"

Enemy::Enemy(void){}
Enemy::Enemy(int hp, std::string const& type): type(type), hit_points(hp){}
Enemy::Enemy(const Enemy& e){*this = e;}
Enemy::~Enemy(void){}

Enemy& Enemy::operator=(const Enemy& e){
    this->hit_points = e.getHP();
    this->type = e.getType();
    return (*this);
}

void Enemy::takeDamage(int amount){
    if (amount <= 0)
        return ;
    int aux = this->hit_points - amount;
    this->hit_points = aux > 0 ? aux : 0;
}

const std::string&  Enemy::getType(void) const{return (this->type);}
int                 Enemy::getHP(void) const{return (this->hit_points);}