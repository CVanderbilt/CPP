#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class Ninjatrap: virtual public Claptrap
{
    public:
        Ninjatrap(void);
        Ninjatrap(std::string name);
        Ninjatrap(Ninjatrap const &ft);
        ~Ninjatrap(void);
        void ninjaShoebox(Fragtrap &ft);
        void ninjaShoebox(Scavtrap &st);
        void ninjaShoebox(Ninjatrap &nt);
        
        void operator=(Ninjatrap const &ft);

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
};

#endif