#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP
# include "ISpaceMarine.hpp"

class TacticalMarine: public ISpaceMarine
{
    private:

    public:
        TacticalMarine(void);								//default constructor
        TacticalMarine(const TacticalMarine&);				//copy constructor
        virtual ~TacticalMarine(void);						//destructor

        TacticalMarine& operator=(const TacticalMarine&);	//=operator

        ISpaceMarine *clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;
};


#endif