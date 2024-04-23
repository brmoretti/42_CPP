/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/23 17:48:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat	tmp = Bureaucrat();

	//Junior

	try {
		std::cout << BOLD(
			"\nCreating a Bureaucrat with the lowest grade possible") \
			<< std::endl;
		Bureaucrat	junior("Junior Bureaucrat", 150);
		tmp = junior;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nTrying to decrement the lowest grade possible") \
			<< std::endl;
		tmp.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << tmp << std::endl;

	try {
		std::cout << BOLD(
			"\nTrying to increment the lowest grade possible") \
			<< std::endl;
		tmp.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << tmp << std::endl;

	//BOSS

	try {
		std::cout << BOLD(
			"\nCreating a Bureaucrat with the highest grade possible") \
			<< std::endl;
		Bureaucrat	boss("MEGABOSS", 1);
		tmp = boss;
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nTrying to increment the highest grade possible") \
			<< std::endl;
		tmp.incrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << tmp << std::endl;

	try {
		std::cout << BOLD(
			"\nTrying to decrement the highest grade possible") \
			<< std::endl;
		tmp.decrementGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << tmp << std::endl;

	return 0;
}
