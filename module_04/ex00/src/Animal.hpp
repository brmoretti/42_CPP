/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:34:24 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 18:51:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

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
