#include <iostream>
#include "Zombie.hpp"

class ZombieHorde
{
    private:
        static const std::string names_list[];
        static const int names;
        void buildList(int size);
        int size;
        Zombie *list;
    public:
        ZombieHorde(void);
        ZombieHorde(int size);
        ~ZombieHorde(void);
        
        void setNames(void);
        void setTypes(int start, int end, std::string type);
        void announce(void);


        
};