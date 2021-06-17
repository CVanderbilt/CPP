#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void show(Character *c){
    std::cout << "  SHOWING..." << std::endl;
    for (int i = 0; i < c->getAmount(); i++)
        std::cout << "	" << c->getMateria(i)->getType() << "(" << c->getMateria(i)->getXP() << ")" << std::endl;;
}

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(5, *bob);

	show((Character *)me);
	AMateria* tmp2;
	tmp2 = src->createMateria("kk");
	me->equip(tmp2);
	tmp2 = src->createMateria("cure");
	me->equip(tmp2);
	tmp2 = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp2);
	tmp2 = src->createMateria("ice");
	me->equip(tmp2);
	delete tmp2;

	show((Character *)me);
	std::cout << "tmp: " << tmp->getType() << ", " << tmp->getXP() << std::endl;

	me->unequip(1);

	show((Character *)me);
	std::cout << "tmp: " << tmp->getType() << ", " << tmp->getXP() << std::endl;

	delete tmp;
	delete bob;
	delete me;
	delete src;

	return (0);
}