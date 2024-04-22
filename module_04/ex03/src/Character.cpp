/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:09:30 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/20 14:46:02 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(const std::string name) :	_name(name),
	_floor(NULL)
{
	for (int i = 0; i < 4; i++) {
		this->_inventory[i] = NULL;
	}
	std::cout << "Character constructor called" << std::endl;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;

	this->clearInventory();
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
		this->cloneInventory(rhs);
	}
	return *this;
}

std::string	const &	Character::getName() const
{
	return this->_name;
}

void	Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << BG_YELLOW(
					m->getType() << " equiped") << std::endl;
			return;
		}
	}
	std::cout << "Inventory is full!" << std::endl;
}

void	Character::unequip(int idx)
{
	AMateria* &	m = this->_inventory[idx];

	if (m == NULL) {
		std::cout << "Nothing to drop" << std::endl;
		return;
	}
	if (this->_floor) {
		this->_floor->drop(m);
		return;
	}
	std::cout << "Set the character floor first";
	std::cout << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (this->_inventory[idx]) {
		this->_inventory[idx]->use(target);
		delete this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void	Character::setFloor(Floor* floor)
{
	this->_floor = floor;
}

Floor*	Character::getFloor() const
{
	return this->_floor;
}

void	Character::clearInventory()
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i]) {
			delete this->_inventory[i];
			this->_inventory[i] = NULL;
		}
	}
}

void	Character::cloneInventory(const Character & character)
{
	this->clearInventory();
	for (int i = 0; i < 4; i++) {
		if (character._inventory[i]) {
			this->_inventory[i] = character._inventory[i]->clone();
		}
	}
}
