/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:25:08 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 17:22:58 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

ScavTrap::ScavTrap() : ClapTrap(),
_gate_keeper_mode(false)
{
	this->_hit_points = HIT_POINTS;
	this->_energy_points = ENERGY_POINTS;
	this->_attack_damage = ATTACK_DAMAGE;
	std::cout << "ScavTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name),
_gate_keeper_mode(false)
{
	this->_hit_points = HIT_POINTS;
	this->_energy_points = ENERGY_POINTS;
	this->_attack_damage = ATTACK_DAMAGE;
	std::cout << "ScavTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " destructor called" << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap & rhs) : ClapTrap(rhs)
{
	*this = rhs;
}

//OPERATORS OVERLOAD

ScavTrap&	ScavTrap::operator=(const ScavTrap & rhs)
{
	if (this != &rhs) {
		(ScavTrap &) this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

//PUBLIC FUNCTIONS

void	ScavTrap::guardGate()
{
	_gate_keeper_mode = true;
	std::cout << "ScavTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_isOk())
		return;
	this->_energy_points--;
	std::cout << "ScavTrap \033[1;33m" << this->_name << "\033[0m attacks ";
	std::cout << "\033[1;31m" << target << "\033[0m ";
	std::cout << "\033[1;34m\"Você ganhou uma maravilhosa lavadoura Brastemp";
	std::cout << " novinha... na cabeça!\"\033[0m";
	std::cout << " causing \033[1;35m" << this->_attack_damage << "\033[0m";
	std::cout << " points of damage!" << std::endl;
}
