/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:16:31 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/23 17:46:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Another Bored Bureaucrat"), _grade(76)
{
	std::cout << MAGENTA(this->_name << " constructor called") << std::endl;
}

Bureaucrat::Bureaucrat(const std::string & name, const int & grade) :
	_name(name)
{
	std::cout << MAGENTA(this->_name << " constructor called") << std::endl;
	if (grade < this->_MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > this->_MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << MAGENTA(this->_name << " destructor called") << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat & rhs)
{
	std::cout << MAGENTA(this->_name << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat & rhs)
{
	std::cout << MAGENTA(this->_name << " '=' overload called") \
		<< std::endl;
	if (this != &rhs) {
		(std::string &)this->_name = rhs._name;
		this->_grade = rhs._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const
{
	return this->_name;
}

int			Bureaucrat::getGrade() const
{
	return this->_grade;
}

void		Bureaucrat::incrementGrade()
{
	if (this->_grade -1 < this->_MAX_GRADE) {
		throw Bureaucrat::GradeTooHighException();
		return;
	}
	this->_grade--;
	std::cout << this->_name << ": grade incremented" << std::endl;
}

void		Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > this->_MIN_GRADE) {
		throw Bureaucrat::GradeTooLowException();
		return;
	}
	this->_grade++;
	std::cout << this->_name << ": grade decremented" << std::endl;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "GradeTooHighException";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "GradeTooLowException";
}

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat & rhs)
{
	lhs << GREEN(rhs.getName()) << WHITE(", bureaucrat grade ") \
		<< GREEN(rhs.getGrade());
	return lhs;
}
