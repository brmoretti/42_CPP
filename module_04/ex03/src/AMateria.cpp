/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 14:47:06 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 16:44:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "Amateria constructor called" << std::endl;
}
AMateria::~AMateria()
{
	std::cout << "Amateria destructor called" << std::endl;
}

AMateria::AMateria(const AMateria & rhs)
{
	*this = rhs;
}

AMateria&			AMateria::operator=(const AMateria & rhs)
{
	if (this != &rhs) {
		if (this->_type != rhs._type) {
			std::cout << "Materias can't change their's types";
			std::cout << std::endl;
		}
	}
	return *this;
}

std::string const &	AMateria::getType() const
{
	return this->_type;
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "Using *nothing* on " << target.getName();
	std::cout << std::endl;
}
