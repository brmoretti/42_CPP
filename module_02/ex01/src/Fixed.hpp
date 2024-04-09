/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:00:36 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 04:13:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
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
	Fixed&	operator=( Fixed const & rhs );

	std::ostream	operator<<( std::ostream const & _cout );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

#endif

