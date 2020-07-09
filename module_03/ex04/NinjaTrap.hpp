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

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
        void ninjaShoebox(Claptrap &cp);
        void ninjaShoebox(Fragtrap &ft);
        void ninjaShoebox(Scavtrap &st);
        void ninjaShoebox(Ninjatrap &nt);
        
        Ninjatrap& operator=(Ninjatrap const &ft);

        static int getInitialHP(void);
        static int getInitialMaxHP(void);
        static int getInitialEnergy(void);
        static int getInitialMaxEnergy(void);
        static int getInitialArmor(void);
        static int getInitialMeleeDmg(void);
        static int getInitialRangedDmg(void);

};

#endif