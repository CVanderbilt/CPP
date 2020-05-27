#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <cstdlib>

const int ZombieHorde::names = 20;
const std::string ZombieHorde::names_list[] = {
    "Kara",
    "Izetta",
    "Sudie",
    "Golden",
    "Shanon",
    "Karey",
    "Corrin",
    "Ward",
    "Jennette",
    "Lore",
    "Felicita",
    "Kathrin",
    "Robt",
    "Melonie",
    "Maudie",
    "Landon",
    "Yuko",
    "Hector",
    "Charla",
    "Marketta"
};

ZombieHorde::ZombieHorde(int size) : list (new Zombie[size]), size(size){}

ZombieHorde::~ZombieHorde(void)
{
    std::cout << "Deleting horde..." << std::endl;
    delete[] (this->list);
    std::cout << "Horde deleted" << std::endl;
}

void    ZombieHorde::setNames(void)
{
    int i;

    i = -1;
    while (++i < this->size)
        this->list[i].setName(this->names_list[rand() % names]);
}

void    ZombieHorde::setTypes(int start, int end, std::string type)
{
    int i;

    if (start >= 0 && start <this->size)
    {
       i = start - 1;
       while (++i <= end && i < this->size)
           this->list[i].setType(type);
    }
}

void    ZombieHorde::announce(void)
{
    int i;

    i = -1;
    std::cout << "announcing:" << this->size << " zombies" << std::endl; 
    while (++i < this->size)
        this->list[i].announce();
}