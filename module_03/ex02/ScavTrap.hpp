#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class Scavtrap: public Claptrap
{
    private:
        static const std::string challenges_list[];
    public:
        Scavtrap(void);
        Scavtrap(std::string name);
        Scavtrap(Scavtrap const &ft);
        ~Scavtrap(void);
        void challengeNewcomer(void);
        
        void operator=(Scavtrap const &ft);

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
};
#endif