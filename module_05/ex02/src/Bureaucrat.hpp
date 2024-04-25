/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:16:25 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/24 18:04:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# define BOLD(text) "\033[1m" << text << "\033[0m"
# define GREEN(text) "\033[32m" << text << "\033[0m"
# define WHITE(text) "\033[37m" << text << "\033[0m"
# define MAGENTA(text) "\033[35m" << text << "\033[0m"
# define RED(text) "\033[31m" << text << "\033[0m"

# include "Form.hpp"

class Form;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(const std::string & name, const int & grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat & rhs);
	Bureaucrat&	operator=(const Bureaucrat & rhs);

	std::string			getName() const;
	int					getGrade() const;

	void				incrementGrade();
	void				decrementGrade();

	void				signForm(Form& form);

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
	int					_grade;
};

std::ostream&	operator<<(std::ostream& lhs, const Bureaucrat & rhs);

#endif
