#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP
# include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weapon;
        //Only pointer is valid, weapon not initialized in constructor
    public:
        HumanB(void);
        HumanB(std::string name);

        void setWeapon(Weapon &weapon);
        void attack(void);
};

#endif