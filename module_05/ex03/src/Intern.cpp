/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:23:32 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/27 17:16:55 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << BLACK("Poor Intern constructor called") << std::endl;
}

Intern::~Intern()
{
	std::cout << BLACK("Poor Intern destructor called") << std::endl;
}

Intern::Intern(const Intern & rhs)
{
	std::cout << BLACK("Poor Intern copy constructor called") \
		<< std::endl;
	*this = rhs;
}

Intern&	Intern::operator=(const Intern & rhs)
{
	std::cout << BLACK("Poor Intern '=' overload called") \
		<< std::endl;
	(void)rhs;
	return *this;
}

AForm*	Intern::makeForm(
	const std::string & form, const std::string & target)
{
	const std::string	forms_names[] = {"shrubbery creation",
										"robotomy request",
										"presidential pardon"};

	FormFunction		formFunctions[] = {&Intern::makeShrubberyCreation,
											&Intern::makeRobotomyRequest,
											&Intern::makePresidentialPardon};

	for (int i = 0; i < this->_KNOWN_FORMS; i++) {
		if (!form.compare(forms_names[i])) {
			return (this->*formFunctions[i])(target);
		}
	}

	throw (FormNotFoundException());
}

const char* Intern::FormNotFoundException::what(void) const throw()
{
	return "\033[30mIntern: FormNotFoundException\033[0m";
}

AForm*	Intern::makeShrubberyCreation(const std::string & target)
{
	return new ShrubberyCreationForm(target);
}
AForm*	Intern::makeRobotomyRequest(const std::string & target)
{
	return new RobotomyRequestForm(target);
}
AForm*	Intern::makePresidentialPardon(const std::string & target)
{
	return new PresidentialPardonForm(target);
}
