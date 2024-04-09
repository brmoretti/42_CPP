/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:00:36 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/08 19:24:44 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_int;
	static const int	_frac = 8;

public:
	Fixed( void );
	~Fixed( void );
	Fixed( Fixed const & src );
	Fixed&	operator=( Fixed const & rhs );
}

#endif
