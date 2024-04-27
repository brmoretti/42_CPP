/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/26 18:58:59 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Presidential Pardon Form",
		PRESIDENTIAL_SIGN_GRADE,
		PRESIDENTIAL_EXEC_GRADE),
	_target("UNDEFINED")
{
	std::cout << BLUE(getName() << " constructor called") << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) :
	AForm("Presidential Pardon Form",
		PRESIDENTIAL_SIGN_GRADE,
		PRESIDENTIAL_EXEC_GRADE),
	_target(target)
{
	std::cout << BLUE(getName() << " constructor called") << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << BLUE(getName() << " destructor called") << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& rhs) :
	AForm("Presidential Pardon Form",
		PRESIDENTIAL_SIGN_GRADE,
		PRESIDENTIAL_EXEC_GRADE)
{
	std::cout << BLUE(this->getName() << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

PresidentialPardonForm&
	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << BLUE(this->getName() << " '=' overload called") \
		<< std::endl;
	if (this != &rhs) {
		AForm::operator=(rhs);
		(std::string &)this->_target = rhs._target;
	}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat &bureaucrat) const
{
	if (!this->isSigned()) {
		throw AForm::FormNotSignedException();
	}

	if (bureaucrat.getGrade() > PRESIDENTIAL_EXEC_GRADE) {
		throw AForm::GradeTooLowException();
	}

	std::cout << BLUE(this->_target << " was pardoned by Zaphod Beeblebrox") \
		<< std::endl;

}

