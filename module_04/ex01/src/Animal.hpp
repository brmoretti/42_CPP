/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:34:24 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 11:27:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

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

class Animal
{
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal & rhs);
	Animal&	operator=(const Animal & rhs);
	std::string		getType() const;
	void			setType(const std::string& type);
	virtual void	makeSound() const;

protected:
	std::string	type;

};

#endif
