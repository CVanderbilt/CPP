#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include <iostream>

class AMateria;

# include "ICharacter.hpp"

class AMateria
{
    private:
        AMateria(void);
        std::string type;
        unsigned int _xp;
    protected:
        void setXp(int);
    public:
        AMateria(std::string const & type);
        AMateria(const AMateria &AMateria);
        virtual ~AMateria(void);
        AMateria& operator=(const AMateria&);

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);

        std::string const & getType() const;
        unsigned int getXP() const;
};

#endif