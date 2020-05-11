#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class Supertrap: public Fragtrap, public Ninjatrap{
    private:
    public:
        Supertrap(void);
        Supertrap(std::string otherName);
        ~Supertrap(void);
        void meleeAttack(std::string target);
        void rangedAttack(std::string target);
};
#endif