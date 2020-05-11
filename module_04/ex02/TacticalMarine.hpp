#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
    private:

    public:
        TacticalMarine(void);
        TacticalMarine(const TacticalMarine&);
        virtual ~TacticalMarine(void);

        TacticalMarine& operator=(const TacticalMarine&);

        ISpaceMarine *clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;
};


#endif