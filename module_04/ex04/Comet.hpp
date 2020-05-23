#ifndef COMET_HPP
# define COMET_HPP

# include "IAsteroid.hpp"

class Comet: public IAsteroid
{
    private:
    public:
        Comet(void);
        Comet(const Comet&);
        virtual ~Comet(void);

        Comet& operator=(const Comet&);

        std::string beMined(DeepCoreMiner*) const;
        std::string beMined(StripMiner*) const;
        std::string getName() const;

};

#endif