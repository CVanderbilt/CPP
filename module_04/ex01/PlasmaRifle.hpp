#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    private:
    public:
        PlasmaRifle(void);
        PlasmaRifle(const PlasmaRifle&);
        virtual ~PlasmaRifle(void);

        PlasmaRifle & operator=(const PlasmaRifle &);

        void attack(void) const;
};

#endif