/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrapp.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:13:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/11 18:00:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( std::string name ) : _name(name), _hit_points(10),
_energy_points(10), _attack_damage(0)
{
}

ClapTrap::~ClapTrap()
{
}

ClapTrap::ClapTrap(const ClapTrap & rhs)
{
	*this = rhs;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap & rhs)
{
	if (this != &rhs) {
		this->_name = rhs._name;
		this->_hit_points = rhs._hit_points;
		this->_energy_points = rhs._energy_points;
		this->_attack_damage = rhs._attack_damage;
	}
	return *this;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_isDead()) {
		this->_cantDoMsg("attack", IS_DEAD);
		return ;

	this->_energy_points--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	this->_hit_points -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->_hit_points += amount;
	this->_energy_points--;
}

player_status	ClapTrap::_getPlayerStatus( void );
{
	if (this->_hit_points <= 0)
		return IS_DEAD;

}

void		ClapTrap::_cantDoMsg( std::string action,
	player_status status )
{
	std::cout << "\033[1;32m" << this->_name << "\033[0m";
	std::cout << ": can't ";
	std::cout << action;
	std::cout << " because he's ";
	if (status == IS_DEAD)
		std::cout << "\033[1;31mDEAD\033[0m";
	else if (status == IS_EXAUSTED)
		std::cout << "\033[1;33mTIRED\033[0m";
	std::cout << endl;
}
