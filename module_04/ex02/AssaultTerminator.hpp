#ifndef ASSAULTTERMINATOR_HPP_HPP
# define ASSAULTTERMINATOR_HPP_HPP
# include "ISpaceMarine.hpp"

class AssaultTerminator: public ISpaceMarine
{
    private:

    public:
        AssaultTerminator(void);
        AssaultTerminator(const AssaultTerminator&);
        virtual ~AssaultTerminator(void);

        AssaultTerminator& operator=(const AssaultTerminator&);

        ISpaceMarine *clone(void) const;
        void battleCry(void) const;
        void rangedAttack(void) const;
        void meleeAttack(void) const;
};


#endif