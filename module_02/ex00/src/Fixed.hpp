/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:00:36 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 03:58:21 by bmoretti         ###   ########.fr       */
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
	~Fixed( void );
	Fixed( Fixed const & src );
	Fixed&	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif

