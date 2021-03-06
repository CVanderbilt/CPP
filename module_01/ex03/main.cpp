#include "ZombieHorde.hpp"
#include "Zombie.hpp"
#include <iostream>

int main()
{
    std::cout << "" << std::endl;
    ZombieHorde *horde = new ZombieHorde(15);

    srand (time(NULL));
    horde->setNames();
    horde->setTypes(0, 10, "smol");
    horde->setTypes(9, 30, "crawler");
    horde->announce();
    std::cout << "" << std::endl;
    delete (horde);
    std::cout << "" << std::endl;
    ZombieHorde horde2(67);
    horde2.setNames();
    horde2.setTypes(15, 33, "big");
    horde2.setTypes(50, 80, "mute");
    horde2.setTypes(44, 44, "special");
    horde2.announce();
    std::cout << "" << std::endl;
    return (0);
}