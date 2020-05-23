#ifndef DEEPCOREMINER_HPP
# define DEEPCOREMINER_HPP

# include "IMiningLaser.hpp"

class DeepCoreMiner: public IMiningLaser
{
    private:
    public:
        DeepCoreMiner(void);
        DeepCoreMiner(const DeepCoreMiner&);
        virtual ~DeepCoreMiner(void);

        DeepCoreMiner& operator=(const DeepCoreMiner&);

        void mine(IAsteroid*);
};

#endif