/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:19:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/08 21:07:09 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _int(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_int = rhs._int;
	return *this;
}
