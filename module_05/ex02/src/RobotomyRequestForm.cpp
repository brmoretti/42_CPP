/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/26 18:43:55 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Robotomy Request Form",
		ROBOTOMY_SIGN_GRADE,
		ROBOTOMY_EXEC_GRADE),
	_target("UNDEFINED")
{
	std::cout << BROWN(getName() << " constructor called") << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) :
	AForm("Robotomy Request Form",
		ROBOTOMY_SIGN_GRADE,
		ROBOTOMY_EXEC_GRADE),
	_target(target)
{
	std::cout << BROWN(getName() << " constructor called") << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << BROWN(getName() << " destructor called") << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& rhs) :
	AForm("Robotomy Request Form",
		ROBOTOMY_SIGN_GRADE,
		ROBOTOMY_EXEC_GRADE)
{
	std::cout << BROWN(this->getName() << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

RobotomyRequestForm&
	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << BROWN(this->getName() << " '=' overload called") \
		<< std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		(std::string &)this->_target = rhs._target;
	}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat &bureaucrat) const
{
	if (!this->isSigned()) {
		throw AForm::FormNotSignedException();
	}

	if (bureaucrat.getGrade() > ROBOTOMY_EXEC_GRADE) {
		throw AForm::GradeTooLowException();
	}

	std::cout << BROWN("Brirll Brirlll Brirrlllllllllllll") << std::endl;
	if ((rand() + clock())% 2 == 0) {
		std::cout << BROWN("How great! " << this->_target \
			<< " was sucessfully robotomized") << std::endl;
	}
	else {
		std::cout << BROWN("Too bad! " << this->_target \
			<< " robotomization failed") << std::endl;
	}
}

