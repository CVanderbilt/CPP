#ifndef ASTEROID_HPP
# define ASTEROID_HPP

# include "IAsteroid.hpp"

class Asteroid: public IAsteroid
{
    private:
    public:
        Asteroid(void);
        Asteroid(const Asteroid&);
        virtual ~Asteroid(void);

        Asteroid& operator=(const Asteroid&);

        std::string beMined(StripMiner*) const;
        std::string beMined(DeepCoreMiner*) const;
        std::string getName() const;

};

#endif