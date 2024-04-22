/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:09:30 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 15:38:13 by bmoretti         ###   ########.fr       */
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
	if (!m) {
		std::cout << BG_YELLOW(
			"There's no Materia to equip") << std::endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			std::cout << BG_YELLOW(m->getType() << " equiped (Slot ";
			std::cout << i << ")") << std::endl;
			return;
		}
	}
	std::cout << BG_YELLOW("Inventory is full!") << std::endl;
}

void	Character::unequip(int idx)
{
	AMateria* &	m = this->_inventory[idx];

	if (!m) {
		std::cout << BG_YELLOW("Nothing to drop") << std::endl;
		return;
	}
	if (this->_floor) {
		this->_floor->drop(m);
		m = NULL;
		return;
	}
	std::cout << BG_YELLOW("Set the character floor first");
	std::cout << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	AMateria* &	m = this->_inventory[idx];

	if (m) {
		m->use(target);
		delete m;
		m = NULL;
		return;
	}
	std::cout << BG_YELLOW("Nothing to use") << std::endl;
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
