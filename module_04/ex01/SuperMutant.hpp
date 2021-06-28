#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP
# include "Enemy.hpp"
# include <iostream>

class SuperMutant: public Enemy
{
    private:
    public:
        SuperMutant(void);							//default constructor
        SuperMutant(const SuperMutant&);			//copy constructor
        virtual ~SuperMutant(void);					//destructor

        SuperMutant& operator=(const SuperMutant&);	//=operator

        void takeDamage(int);
};

#endif