/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:00:36 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 10:10:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_fixed;
	static const int	_fractional = 8;

public:
	Fixed( void );
	Fixed( const int number );
	Fixed( const float number );
	~Fixed( void );
	Fixed( Fixed const & src );
	Fixed&					operator=( Fixed const & rhs );

	bool					operator>( Fixed const & rhs ) const;
	bool					operator<( Fixed const & rhs ) const;
	bool					operator>=( Fixed const & rhs ) const;
	bool					operator<=( Fixed const & rhs ) const;
	bool					operator==( Fixed const & rhs ) const;
	bool					operator!=( Fixed const & rhs ) const;
	Fixed					operator+( Fixed const & rhs ) const;
	Fixed					operator-( Fixed const & rhs ) const;
	Fixed					operator*( Fixed const & rhs ) const;
	Fixed					operator/( Fixed const & rhs ) const;
	Fixed&					operator++( void );
	Fixed&					operator--( void );
	Fixed					operator++( int );
	Fixed					operator--( int );
	static Fixed&			min( Fixed & a, Fixed & b );
	static const Fixed&		min( Fixed const & a, Fixed const & b );
	static Fixed&			max( Fixed & a, Fixed & b );
	static const Fixed&		max( Fixed const & a, Fixed const & b );

	int						getRawBits( void ) const;
	void					setRawBits( int const raw );
	float					toFloat( void ) const;
	int						toInt( void ) const;
};

std::ostream&				operator<<( std::ostream & _cout,
							Fixed const & fixed);

#endif

