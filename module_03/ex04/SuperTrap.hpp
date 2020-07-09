#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP
# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "NinjaTrap.hpp"

class Supertrap: public Fragtrap, public Ninjatrap{
    public:
        Supertrap(void);
        Supertrap(std::string otherName);
        Supertrap(const Supertrap& sp);
        ~Supertrap(void);

        Supertrap& operator=(const Supertrap&);

        void meleeAttack(std::string target);
        void rangedAttack(std::string target);
};
#endif