/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/27 16:49:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main()
{
	Intern	someRandomIntern;
	AForm*	tmp;

	std::cout << BOLD("\nROBOTOMY REQUEST") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("robotomy request", "Bender");
		delete tmp;
	}
	catch (Intern::FormNotFoundException &e) {
		std::cout << WHITE("Form not found!") << std::endl;
	}

	std::cout << BOLD("\nSHRUBBERY CREATION") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("shrubbery creation", "Downtown");
		delete tmp;
	}
	catch (Intern::FormNotFoundException &e) {
		std::cout << WHITE("Form not found!") << std::endl;
	}

	std::cout << BOLD("\nPRESIDENTIAL PARDON") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("presidential pardon",
			"corrupt politician");
		delete tmp;
	}
	catch (Intern::FormNotFoundException &e) {
		std::cout << WHITE("Form not found!") << std::endl;
	}

	std::cout << BOLD("\nTAX EXEMPTION") << std::endl;
	try {
		tmp = someRandomIntern.makeForm("tax exemption", "Bruno Moretti");
		delete tmp;
	}
	catch (Intern::FormNotFoundException &e) {
		std::cout << WHITE("Form not found!") << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
