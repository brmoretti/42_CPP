/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:35:06 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 18:18:36 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& weapon )
			: _name(name), _weapon(weapon)
{
}
HumanA::~HumanA( void )
{
}

void	HumanA::attack( void ) const
{
	std::cout << "\033[1;32m" << this->_name << "\033[0m";
	std::cout << " attacks with their ";
	std::cout << "\033[1;35m" << this->_weapon.getType() << "\033[0m";
	std::cout << std::endl;
}
