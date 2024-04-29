/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:55:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/29 16:05:28 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Another Non-sense Form"),
				_signed(false),
				_sign_req(150),
				_exec_req(150)
{
	std::cout << CYAN(this->_name << " constructor called") << std::endl;
}

AForm::AForm(const std::string& name, const int& sign_req,
	const int& exec_req) :
	_name(name),
	_signed(false),
	_sign_req(sign_req),
	_exec_req(exec_req)
{
	std::cout << CYAN(this->_name << " constructor called") << std::endl;
	if (sign_req > this->_MIN_GRADE || exec_req > this->_MIN_GRADE) {
		throw AForm::GradeTooLowException();
	}
	if (sign_req < this->_MAX_GRADE || exec_req < this->_MAX_GRADE) {
		throw AForm::GradeTooHighException();
	}
}

AForm::~AForm()
{
	std::cout << CYAN(this->_name << " destructor called") << std::endl;
}

AForm::AForm(const AForm& rhs) : _sign_req(150), _exec_req(150)
{
	std::cout << CYAN(this->_name << " copy constructor called") \
		<< std::endl;
	*this = rhs;
}

AForm&	AForm::operator=(const AForm& rhs)
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

std::string	AForm::getName() const
{
	return this->_name;
}

bool		AForm::isSigned() const
{
	return this->_signed;
}

int			AForm::getSignReq() const
{
	return this->_sign_req;
}

int			AForm::getExecReq() const
{
	return this->_exec_req;
}

void		AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_sign_req) {
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "\033[31mAForm: GradeTooHighException\033[0m";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "\033[31mAForm: GradeTooLowException\033[0m";
}

const char*	AForm::FormNotSignedException::what(void) const throw()
{
	return "\033[31mAForm: FormNotSignedException\033[0m";
}

std::ostream&	operator<<(std::ostream& lhs, const AForm& rhs)
{
	lhs << GREEN(rhs.getName()) << WHITE(", required grade to sign ") \
		<< GREEN(rhs.getSignReq()) << WHITE(" , required grade to execute ") \
		<< GREEN(rhs.getExecReq()) << WHITE(". Is signed: ") \
		<< GREEN(rhs.isSigned());
	return lhs;
}
