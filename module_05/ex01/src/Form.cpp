/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:55:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/24 18:06:12 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Another Non-sense Form"),
				_signed(false),
				_sign_req(150),
				_exec_req(150)
{
	std::cout << CYAN(this->_name << " constructor called") << std::endl;
}

Form::Form(const std::string& name, const int& sign_req,
	const int& exec_req) :
	_name(name),
	_signed(false),
	_sign_req(sign_req),
	_exec_req(exec_req)
{
	std::cout << CYAN(this->_name << " constructor called") << std::endl;
	if (sign_req > this->_MIN_GRADE || exec_req > this->_MIN_GRADE) {
		throw Form::GradeTooLowException();
		return;
	}
	if (sign_req < this->_MAX_GRADE || exec_req < this->_MAX_GRADE) {
		throw Form::GradeTooHighException();
		return;
	}
}

Form::~Form()
{
	std::cout << CYAN(this->_name << " destructor called") << std::endl;
}
Form::Form(const Form& rhs) : _sign_req(150), _exec_req(150)
{
	*this = rhs;
}
Form&	Form::operator=(const Form& rhs)
{
	std::cout << CYAN(this->_name << " '=' overload called") \
		<< std::endl;
	if (this != &rhs) {
		(std::string &)this->_name = rhs._name;
		this->_signed = rhs._signed;
		(int &)this->_sign_req = rhs._sign_req;
		(int &)this->_exec_req = rhs._exec_req;
	}
	return *this;
}

std::string	Form::getName() const
{
	return this->_name;
}

bool		Form::isSigned() const
{
	return this->_signed;
}

int			Form::getSignReq() const
{
	return this->_sign_req;
}

int			Form::getExecReq() const
{
	return this->_exec_req;
}

void		Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_req) {
		throw Form::GradeTooLowException();
		return;
	}
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "\033[31mForm: GradeTooHighException\033[0m";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "\033[31mForm: GradeTooLowException\033[0m";
}

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs)
{
	lhs << GREEN(rhs.getName()) << WHITE(", required grade to sign ") \
		<< GREEN(rhs.getSignReq()) << WHITE(" , required grade to execute ") \
		<< GREEN(rhs.getExecReq()) << WHITE(". Is signed: ") \
		<< GREEN(rhs.isSigned());
	return lhs;
}
