/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:29 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/26 16:19:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# define BROWN(text) "\033[33m" << text << "\033[0m"

# include "AForm.hpp"
# include <cstdlib>

# define ROBOTOMY_SIGN_GRADE 72
# define ROBOTOMY_EXEC_GRADE 45

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string & target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& rhs);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);

	void	execute(Bureaucrat &bureaucrat) const;

private:
	const std::string	_target;

};

#endif
