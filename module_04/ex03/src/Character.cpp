/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:09:30 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 18:09:03 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) : _name(name)
{
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
}

Character::Character(const Character & rhs)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = rhs;
}

Character&	Character::operator=(const Character & rhs)
{
	std::cout << "Character '=' operator overload called" << std::endl;
	if (this != &rhs) {
		this->_name = rhs._name;
	}
}

std::string	const &	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{

}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, ICharacter& target)
{

}
