/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:25:50 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:42 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N_ANIMALS 4

int main()
{
	{
		std::cout << GREEN << "***SUBJECT TESTS 1***" << RESET << std::endl;

		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;
		delete i;
	}
	{
		std::cout << GREEN << "\n***SUBJECT DEMAND***" << RESET << std::endl;

		Animal* animals[N_ANIMALS];

		std::cout << WHITE << "\n---Filling array loop---" << RESET << std::endl;
		for (int i = 0; i < N_ANIMALS; i++) {
			if (i < N_ANIMALS / 2)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}
		std::cout << WHITE << "\n---Deleting loop---" << RESET << std::endl;
		for (int i = 0; i < N_ANIMALS; i++) {
			delete animals[i];
		}
	}
	{
		std::cout << GREEN << "\n***DEEP COPY TEST***" << RESET << std::endl;

		Dog*	caramelo = new Dog();
		Dog*	viralata = new Dog();
		Cat*	garfield = new Cat();

		caramelo->accessBrain()->setIdea(0, "Se pá mordo esse carteiro...");
		std::cout << WHITE << "\nIdea 0 from Caramelo:" << RESET << std::endl;
		std::cout << caramelo->accessBrain()->getIdea(0) << std::endl;

		viralata->accessBrain()->setIdea(0, "BR BR HEUHEUHEUEHUEH");
		std::cout << WHITE << "Idea 0 from Viralata:" << RESET << std::endl;
		std::cout << viralata->accessBrain()->getIdea(0) << std::endl;

		std::cout << WHITE << "\nWEIRD! Viralata downloaded Caramelo's brain";
		std::cout << RESET << std::endl;
		*viralata = *caramelo;

		std::cout << WHITE << "\nIdea 0 from Caramelo:" << RESET << std::endl;
		std::cout << caramelo->accessBrain()->getIdea(0) << std::endl;
		std::cout << WHITE << "Idea 0 from Viralata:" << RESET << std::endl;
		std::cout << viralata->accessBrain()->getIdea(0) << std::endl;

		std::cout << WHITE << "\nThe postman is in trouble!";
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nCaramelo changed it's idea...";
		std::cout << RESET << std::endl;
		caramelo->accessBrain()->setIdea(0, "Vou pegar o motoboy!");
		std::cout << caramelo->accessBrain()->getIdea(0) << std::endl;

		std::cout << WHITE << "\n...but Viralata didn't";
		std::cout << RESET << std::endl;
		std::cout << viralata->accessBrain()->getIdea(0) << std::endl;

		delete caramelo;
		delete viralata;
		delete garfield;
	}
	return 0;
}
