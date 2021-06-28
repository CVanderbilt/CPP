#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include "Enemy.hpp"
# include <iostream>

class RadScorpion: public Enemy
{
    private:
    public:
        RadScorpion(void);							//default constructor
        RadScorpion(const RadScorpion&);			//copy constructor
        virtual ~RadScorpion(void);					//destructor

        RadScorpion& operator=(const RadScorpion&);	//=operator
};

#endif