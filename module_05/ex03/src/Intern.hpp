/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:01:01 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/27 23:33:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# define BLACK(text) "\033[30m" << text << "\033[0m"

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern & rhs);
	Intern&	operator=(const Intern & rhs);

	AForm*	makeForm(const std::string & form, const std::string & target);

	class FormNotFoundException : public std::exception
	{
		public:
			virtual const char* what(void) const throw();
	};

private:
	typedef AForm*	(Intern::*FormFunction)(const std::string&);

	const static int			_KNOWN_FORMS = 3;

	AForm*	makeShrubberyCreation(const std::string & target);
	AForm*	makeRobotomyRequest(const std::string & target);
	AForm*	makePresidentialPardon(const std::string & target);

};

#endif
