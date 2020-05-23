#include <iostream>
#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string name): name(name), amount(0){}
Character::Character(const Character& c){*this = c;}
Character::~Character(void){
    for (int i = 0; i < this->amount; i++)
        if (this->arr[i])
            delete (this->arr[i]);
}

Character& Character::operator=(const Character& c){
    this->name = c.getName();
    for (int i = 0; i <= this->amount; i++)
        delete (this->arr[i]);
    for (int i = 0; i <= c.getAmount(); i++)
        this->arr[i] = c.getMateria(i)->clone();
    this->amount = c.getAmount();
    return (*this);
}

void Character::equip(AMateria* m)
{
    int index = 0;
    std::cout << "Equip: " << m << "; amount: " << this->amount << std::endl;
    if (!m)
        return ;
    if (this->amount >= 4)
        return ;
    
    for (int i = 0; i < this->amount; i++)
    {
        //std::cout << "      LOOP compara: " << this->arr[i] << std::endl;
        if (this->arr[i] == m)
        {
            std::cout << "  Ya lo conoce, m (" << m << ") = arr[i] (" << this->arr[i] << ")" << std::endl; 
            return ;
        }
    }
    std::cout << "Succesfully equiped " << m->getType() << std::endl;
    this->arr[amount] = m;
    this->amount++;
}

void Character::unequip(int idx)
{
    //std::cout << "Unequip: " << idx << "; amount " << this->amount << std::endl;
    if (idx < 0 || idx > 3)
        return ;
    for (int i = idx; i < this->amount && i != 3; i++)
        this->arr[i] = this->arr[i + 1];
    this->arr[3] = 0;
    this->amount--;
}

void Character::use(int idx, ICharacter& target)
{
    //std::cout << "using: " << idx << "; " << std::endl;
     if (idx >= 0 && idx <= 3)
         if (this->arr[idx])
             this->arr[idx]->use(target);
}

AMateria* Character::getMateria(int idx) const{
    if (idx >= 0 && idx <= 3)
        return (this->arr[idx]);
    return (0);
}

std::string const& Character::getName(void) const{return(this->name);}
int Character::getAmount(void) const{return (this->amount);}