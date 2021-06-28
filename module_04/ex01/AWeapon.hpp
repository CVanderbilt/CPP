#ifndef AWEAPON_HPP
# define AWEAPON_HPP
# include <iostream>

class AWeapon
{
    private:
        AWeapon();							//default constructor						
    protected:
        std::string name;
        int damage;
        int cost;
    public:
        AWeapon(const AWeapon&);			//copy constructor
        AWeapon(std::string const & name, int apcost, int damage);
        virtual ~AWeapon(void);				//destructor

        AWeapon& operator=(const AWeapon&);	//=operator

        virtual void attack() const = 0;

        std::string const &getName(void) const;
        int getAPCost(void) const;
        int getDamage(void) const;
};

#endif