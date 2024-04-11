/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:05:35 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/10 13:53:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed()), _y(Fixed())
{
}

Point::Point( const float x, const float & y ) : _x(Fixed(x)), _y(Fixed(y))
{
}

Point::~Point()
{
}

Point::Point( const Point & src )
{
	*this = src;
}

Point&	Point::operator=( const Point & rhs )
{
	(Fixed &)this->_x = rhs._x;
	(Fixed &)this->_y = rhs._y;
	return (*this);
}

const Fixed	Point::getX( void ) const
{
	return Fixed(this->_x);
}

const Fixed	Point::getY( void ) const
{
	return Fixed(this->_y);
}
