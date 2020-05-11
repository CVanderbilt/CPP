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
        void vaulthunter_dot_exe(std::string const & target);
        
        void operator=(Fragtrap const &ft);

        void meleeAttack(std::string const &target);
        void rangedAttack(std::string const &target);
};
#endif