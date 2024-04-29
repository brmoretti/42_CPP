/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/29 16:04:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Shruberry Creation Form",
		SHRUBBERY_SIGN_GRADE,
		SHRUBBERY_EXEC_GRADE),
	_target("UNDEFINED")
{
	std::cout << YELLOW(getName() << " constructor called") << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) :
	AForm("Shruberry Creation Form",
		SHRUBBERY_SIGN_GRADE,
		SHRUBBERY_EXEC_GRADE),
	_target(target)
{
	std::cout << YELLOW(getName() << " constructor called") << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << YELLOW(getName() << " destructor called") << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& rhs) :
	AForm("Shruberry Creation Form",
		SHRUBBERY_SIGN_GRADE,
		SHRUBBERY_EXEC_GRADE)
{
	std::cout << YELLOW(this->getName() << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << YELLOW(this->getName() << " '=' overload called") \
		<< std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		(std::string &)this->_target = rhs._target;
	}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat &bureaucrat) const
{
	if (!this->isSigned()) {
		throw AForm::FormNotSignedException();
	}

	if (bureaucrat.getGrade() > SHRUBBERY_EXEC_GRADE) {
		throw AForm::GradeTooLowException();
	}

	const std::string fl_name = this->_target + "_shrubberry";

	if (std::ifstream(fl_name.c_str())) {
		throw ShrubberyCreationForm::FileAlreadyExistException();
	}

	std::ofstream out(fl_name.c_str());
	if (!out) {
		throw ShrubberyCreationForm::FailedToOpenException();
	}

	out << ASCII_TREES << std::endl;
}

const char*	ShrubberyCreationForm::FileAlreadyExistException::what(void)
	const throw()
{
	return "\033[31mShrubberyCreationForm: FileAlreadyExistException\033[0m";
}

const char*	ShrubberyCreationForm::FailedToOpenException::what(void)
	const throw()
{
	return "\033[31mShrubberyCreationForm: FailedToOpenException\033[0m";
}
