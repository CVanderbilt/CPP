#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <iostream>
# include "AMateria.hpp"

class Character: public ICharacter
{
    private:
        Character(void);
        std::string name;
        int amount;
        AMateria *arr[4];
    public:
        Character(std::string name);
        Character(const Character&);
        ~Character(void);

        Character& operator=(const Character&);

        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);

        AMateria* getMateria(int index) const;
        std::string const& getName(void) const;
        int getAmount(void) const;
};

#endif