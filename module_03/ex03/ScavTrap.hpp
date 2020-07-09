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

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
        void challengeNewcomer(void);
        
        Scavtrap& operator=(Scavtrap const &ft);
};
#endif