/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:18:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/24 18:48:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	std::cout << BOLD("***FORM CREATION TESTS***") << std::endl;

	try {
		std::cout << BOLD(
			"\nCreating a \"Standard\" form") \
			<< " \nRequires:\nlevel 76 to sign\nlevel 76 to execute"
			<< std::endl;
		Form	tmp = Form("Standard", 76, 76);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nCreating a \"Pope Can Sign\" form") \
			<< " \nRequires:\nlevel -1 to sign\nlevel 76 to execute"
			<< std::endl;
		Form	tmp = Form("Pope Can Sign", -1, 76);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nCreating a \"You Better Call MacGyver\" form") \
			<< " \nRequires:\nlevel 76 to sign\nlevel 0 to execute"
			<< std::endl;
		Form	tmp = Form("You Better Call MacGyver", 76, 0);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nCreating a \"Amoeba Can Sign\" form") \
			<< " \nRequires:\nlevel 151 to sign\nlevel 76 to execute"
			<< std::endl;
		Form	tmp = Form("Amoeba Can Sign", 151, 76);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		std::cout << BOLD(
			"\nCreating a \"My Dog Can Do It\" form") \
			<< " \nRequires:\nlevel 76 to sign\nlevel 200 to execute"
			<< std::endl;
		Form	tmp = Form("My Dog Can Do It", 76, 200);
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << BOLD("\n***SIGNATURE TESTS***") << std::endl;

	Bureaucrat	junior = Bureaucrat("Junior Bureaucrat", 150);
	Bureaucrat	average = Bureaucrat();
	Bureaucrat	boss = Bureaucrat("Boss", 1);

	std::cout << std::endl;

	Form	form = Form("Some Stupid Form", 75, 20);

	std::cout << BOLD(
		"\nJunior will try to sign \"Some Stupid Form\"") \
		<< std::endl;
	junior.signForm(form);

	std::cout << BOLD(
		"\n\"Another Bored Bureaucrat\" will try to sign " \
		<< "\"Some Stupid Form\"") \
		<< std::endl;
	average.signForm(form);
	average.incrementGrade();
	average.signForm(form);

	std::cout << BOLD(
		"\nBoss will try to sign \"Some Stupid Form\"") \
		<< std::endl;
	boss.signForm(form);

	std::cout << std::endl;

	return 0;
}
