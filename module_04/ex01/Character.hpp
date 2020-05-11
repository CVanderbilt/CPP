#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
    private:
        std::string name;
        int action_points;
        AWeapon *w_ptr;
    public:
        Character(std::string const & name);
        Character(const Character&);
        ~Character();

        Character& operator=(const Character&);

        void recoverAP();
        void equip(AWeapon*);
        void attack(Enemy*);

        std::string const   &getName(void) const;
        int                 getActionPoints(void) const;
        AWeapon             *getWeapon(void) const;
};

std::ostream& operator<<(std::ostream& os, const Character& c);

#endif