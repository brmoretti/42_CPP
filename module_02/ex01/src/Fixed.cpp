/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:19:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 04:16:57 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const int number )
{
	
}

Fixed::Fixed( const float number )
{
	
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed&	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return *this;
}

std::ostream	Fixed::operator<<( std::ostream const & _cout )
{
	
}

int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixed;
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "getRawBits member function called" << std::endl;
	this->_fixed = raw;
}

float	Fixed::toFloat( void ) const
{
	
}

int		Fixed::toInt( void ) const
{
	
}
