#include "MininBarge.hpp"
#include "IMiningLaser.hpp"

MiningBarge::MiningBarge(void): amount(0){}
MiningBarge::MiningBarge(const MiningBarge& m){*this = m;}
MiningBarge::~MiningBarge(void){}

MiningBarge& MiningBarge::operator=(const MiningBarge& m){
    this->amount = m.getAmount();
    for (int i = 0; i < m.getAmount(); i++)
        this->arr[i] = m.getTool(i);
    return (*this);
}

void MiningBarge::equip(IMiningLaser* l)
{
    if (this->amount < 4 && l)
    {
        this->arr[this->amount] = l;
        this->amount++;
    }
}
void MiningBarge::mine(IAsteroid* a) const
{
    for (int i = 0; i < this->amount; i++)
        this->arr[i]->mine(a);
}

int MiningBarge::getAmount(void) const{return (this->amount);}
IMiningLaser* MiningBarge::getTool(int idx) const{return (idx >= 0 && idx <= 3 ? this->arr[idx] : 0);}