#ifndef STRIPMINER_HPP
# define STRIPMINER_HPP

# include "IMiningLaser.hpp"

class StripMiner: public IMiningLaser
{
    private:
    public:
        StripMiner(void);
        StripMiner(const StripMiner&);
        virtual ~StripMiner(void);

        StripMiner& operator=(const StripMiner&);

        void mine(IAsteroid*);
};

#endif