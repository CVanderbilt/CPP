#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    private:
    public:
        PlasmaRifle(void);								//default constructor
        PlasmaRifle(const PlasmaRifle&);				//copy constructor
        virtual ~PlasmaRifle(void);						//destructor

        PlasmaRifle & operator=(const PlasmaRifle &);	//=operator

        void attack(void) const;
};

#endif