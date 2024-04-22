/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 14:54:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 15:02:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure::Cure(const Cure & rhs) : AMateria(rhs)
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = rhs;
}

Cure&	Cure::operator=(const Cure & rhs)
{
	std::cout << "Cure '=' operator overload called" << std::endl;
	(void)rhs;
	return *this;
}

AMateria*	Cure::clone() const
{
	Cure*	clone = new Cure();

	*clone = *this;
	return clone;
}

void		Cure::use(ICharacter& target)
{
	std::cout << BG_WHITE(BOLD(
		"* heals " << target.getName();
		std::cout << "'s wounds *")) << std::endl;
}
