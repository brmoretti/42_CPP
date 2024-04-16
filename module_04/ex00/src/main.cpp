/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:25:40 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 11:39:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main()
{
	{
		std::cout << GREEN << "***SUBJECT TESTS 1***" << RESET << std::endl;

		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete j;
		delete i;
	}

	{
		std::cout << GREEN << "\n***SUBJECT TESTS 2***" << RESET << std::endl;

		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();

		std::cout << i->getType() << " " << std::endl;
		i->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
	}
	{
		std::cout << GREEN << "\n***MY TESTS***" << RESET << std::endl;

		Animal*	meta = new Animal();
		Animal* dog = new Dog();
		Animal* cat = new Cat();

		*meta = *dog;
		*cat = *dog;
		std::cout << meta->getType() << " " << std::endl;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;

		meta->makeSound();
		cat->makeSound();
		dog->makeSound();
		std::cout << WHITE << "Wait...What?" << RESET << std::endl;

		delete meta;
		delete dog;
		delete cat;
	}

	return 0;
}
