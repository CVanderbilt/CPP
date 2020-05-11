#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP
# include "Enemy.hpp"
# include <iostream>

class RadScorpion: public Enemy
{
    private:
    public:
        RadScorpion(void);
        RadScorpion(const RadScorpion&);
        virtual ~RadScorpion(void);

        RadScorpion& operator=(const RadScorpion&);
};

#endif