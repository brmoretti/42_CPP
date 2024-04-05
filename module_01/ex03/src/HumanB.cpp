/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:36:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 18:11:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : _name(name)
{
	this->_weapon = NULL;
}

HumanB::~HumanB( void )
{
}

void	HumanB::attack( void ) const
{
	std::cout << "\033[1;32m" << this->_name << "\033[0m";
	std::cout << " attacks with their ";
	if (this->_weapon == NULL)
		std::cout << "\033[1;35m" << "bare hands" << "\033[0m";
	else
		std::cout << "\033[1;35m" << this->_weapon->getType() << "\033[0m";
	std::cout << std::endl;
}

void	HumanB::setWeapon( Weapon& weapon )
{
	this->_weapon = &weapon;
}
