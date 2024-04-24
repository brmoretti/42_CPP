/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:55:22 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/24 17:58:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define CYAN(text) "\033[36m" << text << "\033[0m"

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form();
	Form(const std::string& name, const int& sign_req, const int& exec_req);
	~Form();
	Form(const Form& rhs);
	Form&	operator=(const Form& rhs);

	std::string	getName() const;
	bool		isSigned() const;
	int			getSignReq() const;
	int			getExecReq() const;

	void		beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

private:
	static const int	_MAX_GRADE = 1;
	static const int	_MIN_GRADE = 150;

	const std::string	_name;
	bool				_signed;
	const int			_sign_req;
	const int			_exec_req;

};

std::ostream&	operator<<(std::ostream& lhs, const Form& rhs);

#endif
