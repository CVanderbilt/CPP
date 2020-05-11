#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
# include <iostream>

class Fragtrap
{
    private:
        static const std::string abilities_list[];
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
        Fragtrap(void);
        Fragtrap(std::string name);
        Fragtrap(Fragtrap const &ft);
        ~Fragtrap(void);
        void rangedAttack(std::string const & target);
        void meleeAttack(std::string const & target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        void vaulthunter_dot_exe(std::string const & target);
        
        void operator=(Fragtrap const &ft);

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