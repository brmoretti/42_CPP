/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 15:33:39 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 16:27:04 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type(type)
{
}

Weapon::~Weapon( void )
{
}

const std::string&	Weapon::getType( void ) const
{
	return this->_type;
}

void				Weapon::setType( std::string type )
{
	this->_type = type;
}
