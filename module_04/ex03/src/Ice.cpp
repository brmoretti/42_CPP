/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:41:35 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 17:58:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice::Ice(const Ice & rhs)
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = rhs;
}

Ice&	Ice::operator=(const Ice & rhs)
{
	std::cout << "Ice '=' operator overload called" << std::endl;
	return *this;
}

AMateria*	Ice::clone() const
{
	Ice*	clone = new Ice();

	*clone = *this;
	return clone;
}

void		Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName();
	std::cout << " *" << std::endl;
}
