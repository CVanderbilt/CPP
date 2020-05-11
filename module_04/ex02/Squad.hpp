#ifndef SQUAD_HPP
# define SQUAD_HPP
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad: public ISquad
{
    private:
        int size;
        ISpaceMarine **arr;
    public:
        Squad(void);
        Squad(const Squad&);
        ~Squad(void);

        Squad& operator=(const Squad&);

        int getCount() const;
        ISpaceMarine* getUnit(int) const;
        int push(ISpaceMarine*);
};

#endif