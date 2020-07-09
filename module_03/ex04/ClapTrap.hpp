#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
#include <iostream>

class Claptrap
{
    protected:
        int hit_points;
        int max_hit_points;
        int energy_points;
        int max_energy_points;
        int level;
        std::string name;
        int melee_damage;
        int ranged_damage;
        int armor;
    public:
        Claptrap(void);
        Claptrap(std::string name);
        Claptrap(Claptrap const &ft);
        ~Claptrap(void);

        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        Claptrap& operator=(Claptrap const &ft);

        int getHP(void) const;
        int getMaxHP(void) const;
        int getEnergy(void) const;
        int getMaxEnergy(void) const;
        int getLevel(void) const;
        int getRangedDamage(void) const;
        int getMeleeDamage(void) const;
        int getArmor(void) const;
        std::string getName(void) const;
};

#endif