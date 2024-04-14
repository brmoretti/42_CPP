/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:13:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/13 22:45:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

ClapTrap::ClapTrap() : _name("UNNAMED"),
_hit_points(ClapTrap::HIT_POINTS), _energy_points(ClapTrap::ENERGY_POINTS),
_attack_damage(ClapTrap::ATTACK_DAMAGE)
{
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
_hit_points(ClapTrap::HIT_POINTS), _energy_points(ClapTrap::ENERGY_POINTS),
_attack_damage(ClapTrap::ATTACK_DAMAGE)
{
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap & rhs)
{
	*this = rhs;
}

//OPERATORS OVERLOAD

ClapTrap&	ClapTrap::operator=(const ClapTrap & rhs)
{
	if (this != &rhs) {
		(std::string &) this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

//PUBLIC FUNCTIONS

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_isOk())
		return;
	this->_energy_points--;
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m attacks ";
	std::cout << "\033[1;31m" << target << "\033[0m causing ";
	std::cout << "\033[1;35m" << this->_attack_damage << "\033[0m";
	std::cout << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m took ";
	std::cout << "\033[1;31m" << amount << "\033[0m";
	std::cout << " points of damage" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_isOk())
		return;
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << "ClapTrap \033[1;33m" << this->_name << "\033[0m repaired ";
	std::cout << "\033[1;32m" << amount << "\033[0m";
	std::cout << " points of damage" << std::endl;
}

//ACESSORS

std::string	ClapTrap::getName(void) const
{
	return this->_name;
}

int	ClapTrap::getHitPoints(void) const
{
	return this->_hit_points;
}

int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energy_points;
}

int	ClapTrap::getAttackDamage(void) const
{
	return this->_attack_damage;
}

void	ClapTrap::setAttackDamage(int attack_damage)
{
	this->_attack_damage = attack_damage;
}

//PRIVATE FUNCTIONS

bool	ClapTrap::_isDead(void)
{
	if (this->_hit_points > 0)
		return false;

	std::cout << "ClapTrap \033[1;33m" << this->_name;
	std::cout << "\033[0m is DEAD 💀" << std::endl;
	return true;
}

bool	ClapTrap::_isExausted(void)
{
	if (this->_energy_points > 0)
		return false;
	std::cout << "ClapTrap \033[1;33m" << this->_name;
	std::cout << "\033[0m is EXAUSTED 😵" << std::endl;
	return true;
}

bool	ClapTrap::_isOk(void)
{
	return (!this->_isDead() && !this->_isExausted());
}
