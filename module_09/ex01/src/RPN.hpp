/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 12:57:15 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/09 15:57:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <exception>
# include <iostream>

class RPN
{
public:
	RPN(const std::string & expression);
	~RPN();
	RPN(const RPN& rhs);
	RPN&	operator=(const RPN& rhs);

	void	evaluate();

	class InvalidExpressionException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class DivisionByZero : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	static const std::string	VALID_OPERATORS;

private:
	RPN();

	bool	isValidExpression(const std::string & expression) const;
	void	operations(const size_t pos);

	std::stack<int>	_stack;
	std::string		_expression;

};

#endif
