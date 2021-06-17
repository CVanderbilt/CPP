#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
    private:
        void init(void);
        AMateria* arr[4];
        int amount;
		AMateria* getMateria(int idx) const;
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource&);
        ~MateriaSource(void);

        MateriaSource& operator=(const MateriaSource&);

        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const& type);

        int getAmount(void) const;
};

#endif