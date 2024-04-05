/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 18:56:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 10:58:34 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void )
{
}

Zombie::Zombie( std::string name )
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << "\033[1;31m" << this->name << "\033[0m";
	std::cout << ": Not in my braiiiiiiinnnzzz plan!" << std::endl;
}

void		Zombie::announce( void ) const
{
	std::cout << "\033[1;32m" << this->name << "\033[0m";
	std::cout << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void		Zombie::setName( std::string name )
{
	this->name = name;
}
