#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP
# include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon &weapon;
        //Reference or pointer are valid, weapon initialized in constructor
    public:
        HumanA(std::string name, Weapon &weapon);

        void attack(void);
};

#endif