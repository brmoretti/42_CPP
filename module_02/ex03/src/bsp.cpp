/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:06:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 15:45:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static bool	sign( const Point & p1, const Point & p2, const Point & p3)
{
	Fixed	side;
	Fixed	zero;

	side = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) \
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
	return ( side > zero );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	return sign(point, a, b) == sign(point, b, c) == sign(point, c, a);
}
