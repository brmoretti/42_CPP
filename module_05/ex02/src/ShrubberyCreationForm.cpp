/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/25 01:29:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shruberry", _SIGN_GRADE, _EXEC_GRADE),
	_target("UNDEFINED")
{
	std::cout << YELLOW(getName() << " constructor called") << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) :
	AForm("Shruberry", _SIGN_GRADE, _EXEC_GRADE),
	_target(target)
{
	std::cout << YELLOW(getName() << " constructor called") << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW(getName() << " destructor called") << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs) :
	AForm("Shruberry", _SIGN_GRADE, _EXEC_GRADE)
{
	std::cout << YELLOW(this->getName() << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs) {
		AForm::operator=(rhs);
		(std::string &)this->_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	const std::string fl_name = this->_target + "_shruberry";

	if (std::ifstream(fl_name)) {
		throw ShrubberyCreationForm::FileAlreadyExist();
	}

	std::ofstream out(fl_name);
	if (!out) {
		throw ShrubberyCreationForm::FailedToOpen();
	}

	out << ASCII_TREES << std::endl;
}

const char*	ShrubberyCreationForm::FileAlreadyExist::what(void)
	const throw()
{
	return "\033[31mShrubberyCreationForm: FileAlreadyExist\033[0m";
}

const char*	ShrubberyCreationForm::FailedToOpen::what(void)
	const throw()
{
	return "\033[31mShrubberyCreationForm: FailedToOpen\033[0m";
}
