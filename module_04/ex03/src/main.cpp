/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:44:24 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 15:40:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Floor.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

int main()
{
	{
		std::cout << GREEN("\n*** SUBJECT TEST ***\n") << std::endl;

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

		delete bob;
		delete me;
		delete src;
	}

	{
		std::cout << GREEN("\n*** MY TEST ***\n") << std::endl;

		IMateriaSource* src = new MateriaSource();
		Floor*	floor = new Floor();

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter*	lapras = new Character("Lapras");
		ICharacter* charmander = new Character("Charmander");
		ICharacter* clefairy = new Character("Clefairy");

		AMateria	*ice[5];

		for (int i = 0; i < 5; i++) {
			ice[i] = src->createMateria("ice");
			lapras->equip(ice[i]);
			std::cout << std::endl;
		}

		lapras->unequip(0);
		lapras->setFloor(floor);
		lapras->unequip(0);
		lapras->unequip(0);
		lapras->equip(ice[4]);

		charmander->equip(src->createMateria("fire"));

		clefairy->equip(src->createMateria("cure"));

		lapras->use(0, *charmander);
		lapras->use(0, *charmander);
		lapras->use(1, *charmander);

		std::cout << BOLD("\n Charmander is fainted!! \n") << std::endl;

		clefairy->use(0, *charmander);

		std::cout << BOLD("\n Charmander was healed \n") << std::endl;

		delete src;
		delete lapras;
		delete charmander;
		delete clefairy;
		delete floor;
	}
	return 0;
}
