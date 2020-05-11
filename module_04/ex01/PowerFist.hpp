#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    private:
    public:
        PowerFist(void);
        PowerFist(const PowerFist&);
        virtual ~PowerFist(void);

        PowerFist & operator=(const PowerFist &);

        void attack(void) const;
};

#endif