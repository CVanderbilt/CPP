#ifndef ZOMBIE_EVENT_HPP
# define ZOMBIE_EVENT_HPP
# include <iostream>
# include "Zombie.hpp"

class ZombieEvent
{
    private:
        std::string type;
        static const std::string names_list[];
        static const int names;
    public:
        ZombieEvent();
        ~ZombieEvent();
        
        void    setZombieType(std::string type);
        Zombie  *newZombie(std::string name);
        Zombie  *randomChump(); 
};
#endif