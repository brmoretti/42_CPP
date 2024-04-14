/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:25:08 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 17:22:43 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

FragTrap::FragTrap() : ClapTrap()
{
	this->_hit_points = HIT_POINTS;
	this->_energy_points = ENERGY_POINTS;
	this->_attack_damage = ATTACK_DAMAGE;
	std::cout << "FragTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	this->_hit_points = HIT_POINTS;
	this->_energy_points = ENERGY_POINTS;
	this->_attack_damage = ATTACK_DAMAGE;
	std::cout << "FragTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " destructor called" << std::endl;
}
FragTrap::FragTrap(const FragTrap & rhs) : ClapTrap(rhs)
{
	*this = rhs;
}

//OPERATORS OVERLOAD

FragTrap&	FragTrap::operator=(const FragTrap & rhs)
{
	if (this != &rhs) {
		(FragTrap &) this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

//PUBLIC FUNCTIONS

void	FragTrap::highFivesGuys(void)
{
	if (!this->_isOk())
		return;
	std::cout << "FragTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " is asking for \033[1;32mHigh Fives\033[0m!" << std::endl;
}
