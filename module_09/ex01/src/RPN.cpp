/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 13:13:46 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/09 17:20:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const std::string RPN::VALID_OPERATORS = "/*-+";

RPN::RPN(const std::string & expression) : _expression(expression)
{
	if (!this->isValidExpression(expression)) {
		throw InvalidExpressionException();
	}
	this->_stack.push(0);
}

RPN::~RPN()
{

}

RPN::RPN(const RPN& rhs)
{
	*this = rhs;
}

RPN&	RPN::operator=(const RPN& rhs)
{
	if (this != &rhs) {
		this->_stack = rhs._stack;
	}
	return *this;
}

void	RPN::evaluate()
{
	for (std::string::iterator it = this->_expression.begin();
		it != this->_expression.end(); ++it)
	{
		size_t	oper;

		oper = VALID_OPERATORS.find(*it);
		if (oper != std::string::npos) {
			this->operations(oper);
		}
		else if (std::isdigit(*it)) {
			this->_stack.push(static_cast<int>(*it) - 48);
		}
	}
	std::cout << this->_stack.top() << std::endl;
}

const char * RPN::InvalidExpressionException::what() const throw()
{
	return "Error";
}

const char * RPN::DivisionByZero::what() const throw()
{
	return "Error: Division by zero";
}

RPN::RPN()
{

}

bool	RPN::isValidExpression(const std::string & expression) const
{
	bool	space = true;

	for (std::string::const_iterator it = expression.begin();
		it != expression.end(); ++it)
	{
		if (space
			&& (std::isdigit(*it)
				|| VALID_OPERATORS.find(*it) != std::string::npos))
		{
			space = false;
			continue;
		}
		if (!(space = std::isspace(static_cast<int>(*it))))
		{
			return false;
		}
	}
	return true;
}

void	RPN::operations(const size_t pos)
{
	int	a, b;

	if (this.)

	a = this->_stack.top();
	this->_stack.pop();
	b = this->_stack.top();
	this->_stack.pop();

	switch(pos) {
		case 0:
			if (a == 0) {
				throw DivisionByZero();
			}
			this->_stack.push(b / a);
			break;
		case 1:
			this->_stack.push(b * a);
			break;
		case 2:
			this->_stack.push(b - a);
			break;
		case 3:
			this->_stack.push(b + a);
	}
}
