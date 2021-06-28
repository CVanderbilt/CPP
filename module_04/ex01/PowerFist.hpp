#ifndef POWERFIST_HPP
# define POWERFIST_HPP
# include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    private:
    public:
        PowerFist(void);							//default constructor
        PowerFist(const PowerFist&);				//copy constructor
        virtual ~PowerFist(void);					//destructor

        PowerFist & operator=(const PowerFist &);	//=operator

        void attack(void) const;
};

#endif