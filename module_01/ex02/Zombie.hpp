
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>

class Zombie
{
    private:
        std::string type;
        std::string name;
    public:
        Zombie();
        Zombie(std::string name);
        Zombie(std::string name, std::string type);
        ~Zombie();
        
        void    setName(std::string name);
        void    setType(std::string type);
        void    announce(void);
};
#endif