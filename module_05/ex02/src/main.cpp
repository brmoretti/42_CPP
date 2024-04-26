/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/26 19:01:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main()
{
	Bureaucrat	junior = Bureaucrat("Junior Bureaucrat", 150);
	Bureaucrat	average = Bureaucrat();
	Bureaucrat	boss = Bureaucrat("Boss", 1);

	std::cout << BOLD("\n***SHRUBBERY CREATION FORM***") << std::endl;

	AForm*	tmp = new ShrubberyCreationForm("woods");

	std::cout << BOLD(
		"\n" << junior.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << junior << std::endl;
	junior.signForm(*tmp);

	std::cout << BOLD(
		"\n" << average.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << average << std::endl;
	average.executeForm(*tmp);

	std::cout << BOLD(
		"\n" << average.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << average << std::endl;
	average.signForm(*tmp);

	std::cout << BOLD(
		"\n" << average.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << average << std::endl;
	average.executeForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.executeForm(*tmp);

	std::cout << std::endl;

	delete tmp;

	std::cout << BOLD("\n***ROBOTOMY REQUEST FORM***") << std::endl;

	tmp = new RobotomyRequestForm("Dictator");

	std::cout << BOLD(
		"\n" << junior.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << junior << std::endl;
	junior.signForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.executeForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.signForm(*tmp);

	std::cout << BOLD(
		"\n" << junior.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << junior << std::endl;
	junior.executeForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.executeForm(*tmp);

	std::cout << std::endl;

	delete tmp;

	std::cout << BOLD("\n***PRESIDENTIAL PARDON FORM***") << std::endl;

	tmp = new PresidentialPardonForm("Furious Puppy");

	std::cout << BOLD(
		"\n" << junior.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << junior << std::endl;
	junior.signForm(*tmp);

	std::cout << BOLD(
		"\n" << average.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << average << std::endl;
	average.signForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to sign " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.signForm(*tmp);

	std::cout << BOLD(
		"\n" << boss.getName() << " will try to execute " << tmp->getName()) \
		<< std::endl;
	std::cout << boss << std::endl;
	boss.executeForm(*tmp);

	std::cout << std::endl;

	delete tmp;

	std::cout << std::endl;

	return 0;
}
