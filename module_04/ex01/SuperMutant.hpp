#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"
# include <iostream>

class SuperMutant: public Enemy
{
    private:
    public:
        SuperMutant(void);
        SuperMutant(const SuperMutant&);
        virtual ~SuperMutant(void);

        SuperMutant& operator=(const SuperMutant&);

        void takeDamage(int);
};

#endif