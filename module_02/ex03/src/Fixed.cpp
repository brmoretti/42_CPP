/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:19:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 10:14:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixed(0)
{
}

Fixed::Fixed( const int number ) : _fixed( number << this->_fractional )
{
}

Fixed::Fixed( const float number )
	: _fixed( roundf(number * (1 << this->_fractional)) )
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
}

Fixed&			Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_fixed = rhs.getRawBits();
	return *this;
}

int				Fixed::getRawBits( void ) const
{
	return this->_fixed;
}

void			Fixed::setRawBits( int const raw )
{
	this->_fixed = raw;
}

float			Fixed::toFloat( void ) const
{
	return static_cast<float>(this->getRawBits())
		/ ( 1 << this->_fractional );
}

int				Fixed::toInt( void ) const
{
	return this->_fixed >> this->_fractional;
}

std::ostream&	operator<<( std::ostream & _cout, Fixed const & fixed)
{
	_cout << fixed.toFloat();
	return _cout;
}

bool			Fixed::operator>( Fixed const & rhs ) const
{
	return ( this->getRawBits() > rhs.getRawBits() );
}

bool			Fixed::operator<( Fixed const & rhs ) const
{
	return ( this->getRawBits() < rhs.getRawBits() );
}

bool			Fixed::operator>=( Fixed const & rhs ) const
{
	return ( this->getRawBits() >= rhs.getRawBits() );
}

bool			Fixed::operator<=( Fixed const & rhs ) const
{
	return ( this->getRawBits() <= rhs.getRawBits() );

}

bool			Fixed::operator==( Fixed const & rhs ) const
{
	return ( this->getRawBits() == rhs.getRawBits() );
}

bool			Fixed::operator!=( Fixed const & rhs ) const
{
	return ( this->getRawBits() != rhs.getRawBits() );
}

Fixed			Fixed::operator+( Fixed const & rhs ) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() + rhs.getRawBits());
	return tmp;
}

Fixed			Fixed::operator-( Fixed const & rhs ) const
{
	Fixed	tmp;

	tmp.setRawBits(this->getRawBits() - rhs.getRawBits());
	return tmp;
}

Fixed			Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed			Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

Fixed& 			Fixed::operator++( void )
{
	this->_fixed++;
	return *this;
}

Fixed& 			Fixed::operator--( void )
{
	this->_fixed--;
	return *this;
}

Fixed			Fixed::operator++( int )
{
	Fixed	_tmp( *this );

	this->_fixed++;
	return _tmp;
}

Fixed			Fixed::operator--( int )
{
	Fixed	_tmp( *this );

	this->_fixed--;
	return _tmp;
}

Fixed&			Fixed::min( Fixed & a, Fixed & b )
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::min( Fixed const & a, Fixed const & b )
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

Fixed&			Fixed::max( Fixed & a, Fixed & b )
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

const Fixed&	Fixed::max( Fixed const & a, Fixed const & b )
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}
