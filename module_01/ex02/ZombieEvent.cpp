#include "ZombieEvent.hpp"
#include "Zombie.hpp"
#include <cstdlib>

const int ZombieEvent::names = 20;
const std::string ZombieEvent::names_list[] = {
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

ZombieEvent::ZombieEvent(void): type("basic"){}

ZombieEvent::~ZombieEvent(void){
    std::cout << "event deleted(" << this->type << ")" << std::endl;
}

void    ZombieEvent::setZombieType(std::string type){
    this->type = type;
}

Zombie  *ZombieEvent::newZombie(std::string name){
    return (new Zombie(name, this->type));
}

Zombie  *ZombieEvent::randomChump(){
    return (this->newZombie(this->names_list[rand() % names]));
}