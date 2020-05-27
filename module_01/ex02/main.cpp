#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <iostream>

int main(void)
{
    ZombieEvent small;
    ZombieEvent crawler;
    Zombie *list[10];
    Zombie other_list[5];
    int i;

    std::cout << std::endl;
    srand (time(NULL));
    crawler.setZombieType("crawler");
    small.setZombieType("small");
    i = -1;
    while (++i <= 3){
        list[i] = crawler.randomChump();
        list[i]->announce();
    }
    std::cout << std::endl;
    --i;
    while (++i <= 7){
        list[i] = small.randomChump();
        list[i]->announce();
    }
    list[8] = crawler.newZombie("thelastcrawler");
    list[9] = small.newZombie("thelastsmall");
    list[8]->announce();
    list[9]->announce();
    i = -1;
    std::cout << std::endl;
    while(++i < 10){
        delete(list[i]);
    }
    i = -1;
    while (++i < 5){
        other_list[i].setName("sameZombieOverAndOverXD");
        other_list[i].announce();
    }

    return (0);
}