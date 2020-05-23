#ifndef CURE_HPP
# define CURE_HPP
# include "AMateria.hpp"

class Cure: public AMateria
{
    public:
        Cure(void);
        Cure(const Cure&);
        ~Cure(void);

        Cure& operator=(const Cure&);

        AMateria* clone() const;
        void use(ICharacter& target);
};

#endif