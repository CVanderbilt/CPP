#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
    private:
        AWeapon();
    protected:
        std::string name;
        int damage;
        int cost;
    public:
        AWeapon(const AWeapon&);
        AWeapon(std::string const & name, int apcost, int damage);
        virtual ~AWeapon(void);

        AWeapon& operator=(const AWeapon&);

        virtual void attack() const = 0;

        std::string const &getName(void) const;
        int getAPCost(void) const;
        int getDamage(void) const;
};

#endif