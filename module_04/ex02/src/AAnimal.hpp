/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:34:24 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 15:55:26 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

# define RESET "\033[0m"
# define RED "\033[1;31m"
# define YELLOW "\033[1;33m"
# define GREEN "\033[1;32m"
# define CYAN "\033[1;36m"
# define MAGENTA "\033[1;35m"
# define WHITE "\033[1;37m"
# define BLACK "\033[1;30m"
# define BLUE "\033[1;34m"

class AAnimal
{
public:
	AAnimal();
	virtual ~AAnimal();
	AAnimal(const AAnimal & rhs);
	AAnimal&	operator=(const AAnimal & rhs);
	std::string		getType() const;
	void			setType(const std::string& type);
	virtual void	makeSound() const = 0;

protected:
	std::string	type;

};

#endif
