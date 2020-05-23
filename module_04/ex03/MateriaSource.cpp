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
    //std::cout << "Learning..." << std::endl;
    if (this->amount < 3 && this->amount >= 0)
    {
        this->arr[amount] = m->clone();
        this->amount++;
    }
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
    //std::cout << "Creating(" << type << ")..." << std::endl;
    for (int i = 0; i < this->amount; i++){
        //std::cout << "  comparing with: " << this->arr[i]->getType() << std::endl;
        if (this->arr[i]->getType() == type){
            //std::cout << "      Found: ";
            AMateria* ret = this->arr[i]->clone();
            //std::cout << ret << std::endl;
            return (ret);
            //return (this->arr[i]->clone());
        }
    }
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