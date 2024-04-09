/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:06:27 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 14:43:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;

public:
	Point();
	Point( const float x, const float & y );
	~Point();
	Point( const Point & src );
	Point&	operator=( const Point & rhs );
	const Fixed	getX( void ) const;
	const Fixed	getY( void ) const;
};

#endif
