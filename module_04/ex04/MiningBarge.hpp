#ifndef MININGBARGE_HPP
# define MININGBARGE_HPP

# include "IAsteroid.hpp"
# include "IMiningLaser.hpp"

class MiningBarge
{
    private:
        int amount;
        IMiningLaser *arr[4];
    public:
        MiningBarge(void);
        MiningBarge(const MiningBarge&);
        virtual ~MiningBarge(void);

        MiningBarge& operator=(const MiningBarge&);

        void equip(IMiningLaser*);
        void mine(IAsteroid*) const;

        int getAmount(void) const;
        IMiningLaser* getTool(int idx) const;
};

#endif