#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void): amount(0){}
MateriaSource::MateriaSource(const MateriaSource& m){*this = m;}
MateriaSource::~MateriaSource(void){
    for (int i = 0; i < amount; i++)
        delete (this->arr[i]);
}

MateriaSource& MateriaSource::operator=(const MateriaSource& m){
    for (int i = 1; i <= this->amount; i++)
        delete (this->arr[i]);
    for (int i = 1; i < m.getAmount(); i++)
        this->arr[i] = m.getMateria(i)->clone();
    return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (this->amount < 3 && this->amount >= 0)
    {
        this->arr[amount] = m->clone();
        this->amount++;
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    for (int i = 0; i < this->amount; i++)
        if (this->arr[i]->getType() == type)
            return (this->arr[i]->clone());
    return (0);
}

AMateria* MateriaSource::getMateria(int idx) const{
    if (idx >= 0 && idx < 4)
        return (this->arr[idx]);
    return (0);
}

int MateriaSource::getAmount(void) const{
    return (this->amount);
}