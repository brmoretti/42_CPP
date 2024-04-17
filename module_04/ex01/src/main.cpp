/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 16:25:50 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 10:51:37 by bmoretti         ###   ########.fr       */
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

		const Animal* animals[N_ANIMALS];

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
		std::cout << GREEN << "\n***DOGS' DEEP COPY TEST***" << RESET << std::endl;

		std::cout << WHITE << "\nWelcome Caramelo:" << RESET << std::endl;
		const Dog*	caramelo = new Dog();
		std::cout << WHITE << "\nWelcome Viralata:" << RESET << std::endl;
		const Dog*	viralata = new Dog();

		caramelo->accessBrain()->setIdea(0, "Se pá mordo esse carteiro...");
		std::cout << WHITE << "\nIdea 0 from Caramelo:" << RESET << std::endl;
		std::cout << CYAN << "- " << caramelo->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		viralata->accessBrain()->setIdea(0, "BR BR HEUHEUHEUEHUEH");
		std::cout << WHITE << "Idea 0 from Viralata:" << RESET << std::endl;
		std::cout << MAGENTA << "- " << viralata->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nWEIRD! Viralata downloaded Caramelo's brain";
		std::cout << RESET << std::endl;
		(Dog &) *viralata = *caramelo;

		std::cout << WHITE << "\nIdea 0 from Caramelo:" << RESET << std::endl;
		std::cout << CYAN << "- " << caramelo->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;
		std::cout << WHITE << "Idea 0 from Viralata:" << RESET << std::endl;
		std::cout << MAGENTA << "- " << viralata->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nThe postman is in trouble!";
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nCaramelo changed it's idea...";
		std::cout << RESET << std::endl;
		caramelo->accessBrain()->setIdea(0, "Vou pegar o motoboy!");
		std::cout << CYAN << "- " << caramelo->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\n...but Viralata didn't";
		std::cout << RESET << std::endl;
		std::cout << MAGENTA << "- " << viralata->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nCaramelo entered a cloning machine";
		std::cout << RESET << std::endl;
		const Dog*	caramelo_clone = new Dog(*caramelo);

		std::cout << WHITE << "\nWhat is the clone thinking about?";
		std::cout << RESET << std::endl;
		std::cout << BLUE << "- " << caramelo_clone->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nGood bye Caramelo!";
		std::cout << RESET << std::endl;
		delete caramelo;
		std::cout << WHITE << "\nGood bye Viralata!";
		std::cout << RESET << std::endl;
		delete viralata;
		std::cout << WHITE << "\nGood bye Caramelo's Clone!";
		std::cout << RESET << std::endl;
		delete caramelo_clone;
	}
	{
		std::cout << GREEN << "\n***CATS' DEEP COPY TEST***" << RESET << std::endl;

		std::cout << WHITE << "\nWelcome Garfield:" << RESET << std::endl;
		const Cat*	garfield = new Cat();
		std::cout << WHITE << "\nWelcome Tom:" << RESET << std::endl;
		const Cat*	tom = new Cat();

		garfield->accessBrain()->setIdea(0, "I love lasagna.");
		std::cout << WHITE << "\nIdea 0 from Garfield:" << RESET << std::endl;
		std::cout << CYAN << "- " << garfield->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		tom->accessBrain()->setIdea(0, "Where's the stupid Jerry?");
		std::cout << WHITE << "Idea 0 from Tom:" << RESET << std::endl;
		std::cout << MAGENTA << "- " << tom->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nWEIRD! Tom downloaded Garfield's brain";
		std::cout << RESET << std::endl;
		(Cat &)*tom = *garfield;

		std::cout << WHITE << "\nIdea 0 from Garfield:" << RESET << std::endl;
		std::cout << CYAN << "- " << garfield->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;
		std::cout << WHITE << "Idea 0 from Tom:" << RESET << std::endl;
		std::cout << MAGENTA << "- " << tom->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nThey can't share a lasagna!";
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nGarfield changed it's idea...";
		std::cout << RESET << std::endl;
		garfield->accessBrain()->setIdea(0, "I hate Mondays.");
		std::cout << CYAN << "- " << garfield->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\n...but Tom didn't";
		std::cout << RESET << std::endl;
		std::cout << MAGENTA << "- " << tom->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nGarfield entered a cloning machine";
		std::cout << RESET << std::endl;
		const Cat*	garfield_clone = new Cat(*garfield);

		std::cout << WHITE << "\nWhat is the clone thinking about?";
		std::cout << RESET << std::endl;
		std::cout << BLUE << "- " << garfield_clone->accessBrain()->getIdea(0);
		std::cout << RESET << std::endl;

		std::cout << WHITE << "\nGood bye Garfield!";
		std::cout << RESET << std::endl;
		delete garfield;
		std::cout << WHITE << "\nGood bye Tom!";
		std::cout << RESET << std::endl;
		delete tom;
		std::cout << WHITE << "\nGood bye Garfield's Clone!";
		std::cout << RESET << std::endl;
		delete garfield_clone;
	}

	return 0;
}
