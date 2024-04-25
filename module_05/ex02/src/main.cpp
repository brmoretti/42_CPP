/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/25 12:39:39 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	Bureaucrat	junior = Bureaucrat("Junior Bureaucrat", 150);
	Bureaucrat	average = Bureaucrat();
	Bureaucrat	boss = Bureaucrat("Boss", 1);

	std::cout << BOLD("\n***SHRUBBERY***") << std::endl;

	AForm*	tmp = new ShrubberyCreationForm("test");

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

	delete tmp;

	return 0;
}
