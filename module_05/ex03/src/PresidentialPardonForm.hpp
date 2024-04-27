/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:43:29 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/26 16:09:07 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# define BLUE(text) "\033[34m" << text << "\033[0m"

# include "AForm.hpp"

# define PRESIDENTIAL_SIGN_GRADE 25
# define PRESIDENTIAL_EXEC_GRADE 5

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string & target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& rhs);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& rhs);

	void	execute(Bureaucrat &bureaucrat) const;

private:
	const std::string	_target;

};

#endif
