#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"

class Fragtrap: virtual public Claptrap
{
    private:
        static const std::string abilities_list[];
    public:
        Fragtrap(void);
        Fragtrap(std::string name);
        Fragtrap(Fragtrap const &ft);
        ~Fragtrap(void);

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
        void vaulthunter_dot_exe(std::string const & target);
        
        Fragtrap& operator=(Fragtrap const &ft);

        static int getInitialHP(void);
        static int getInitialMaxHP(void);
        static int getInitialEnergy(void);
        static int getInitialMaxEnergy(void);
        static int getInitialArmor(void);
        static int getInitialMeleeDmg(void);
        static int getInitialRangedDmg(void);
};
#endif