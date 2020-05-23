/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncolomer <ncolomer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:42:26 by ncolomer          #+#    #+#             */
/*   Updated: 2019/12/21 17:11:11 by ncolomer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

void show(Character *c){
    std::cout << "  SHOWING..." << std::endl;
    for (int i = 0; i < c->getAmount(); i++)
        std::cout << "      " << c->getMateria(i)->getType() << std::endl;;
}

int main(void)
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp = nullptr;
	AMateria* first = nullptr;
	tmp = src->createMateria("fire");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	first = tmp;
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	delete tmp;
	me->equip(nullptr);

    show((Character*)me);

	ICharacter* bob = new Character("bob");
	me->use(-1, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(0, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(4, *bob);

    std::cout << "Empieza unequip" << std::endl;
	me->unequip(0);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(0, *bob);
	std::cout << "materia exp: " << first->getXP() << std::endl;
	me->use(3, *bob);
	me->unequip(-1);
    show((Character*)me);
	me->equip(first);
    show((Character*)me);

    std::cout << "Fin" << std::endl;

	delete bob;
	delete me;
	delete src;

	return (0);
}