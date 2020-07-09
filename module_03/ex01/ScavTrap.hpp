#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
# include <iostream>

class Scavtrap
{
    private:
        static const std::string challenges_list[];
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
        Scavtrap(void);
        Scavtrap(std::string name);
        Scavtrap(Scavtrap const &ft);
        ~Scavtrap(void);
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void challengeNewcomer(void);
        
        Scavtrap& operator=(Scavtrap const &ft);

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