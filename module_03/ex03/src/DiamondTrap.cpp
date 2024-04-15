/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 15:19:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 11:27:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

//CONSTRUCTORS & DESTRUCTOR

DiamondTrap::DiamondTrap() : _name("UNNAMED")
{
	(ClapTrap &) ClapTrap::_name = this->_name + "_clap_name";
	this->_hit_points = FragTrap::HIT_POINTS;
	this->_energy_points = ScavTrap::ENERGY_POINTS;
	this->_attack_damage = FragTrap::ATTACK_DAMAGE;
	std::cout << "DiamondTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string name) :
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	//ClapTrap::_name = this->_name + "_clap_name";
	this->_hit_points = FragTrap::HIT_POINTS;
	this->_energy_points = ScavTrap::ENERGY_POINTS;
	this->_attack_damage = FragTrap::ATTACK_DAMAGE;
	std::cout << "DiamondTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap \033[1;33m" << this->_name << "\033[0m";
	std::cout << " destructor called" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap & rhs) : ClapTrap(rhs)
{
	*this = rhs;
}

//OPERATORS OVERLOAD

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap & rhs)
{
	if (this != &rhs) {
		(DiamondTrap &) this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

//PUBLIC FUNCTIONS

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	std::cout << "\033[1;34mWHO AM I??\033[0m\n";
	std::cout << "My name: " << this->_name << "\n";
	std::cout << "My ClapTrap name: " << this->ClapTrap::_name << std::endl;
}
