/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:06:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/10 14:17:48 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static int	sign( const Point & p1, const Point & p2, const Point & p3)
{
	Fixed	side;
	Fixed	zero;

	side = (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) \
		- (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
	if ( side > zero )
		return 1;
	if ( side == zero )
		return 0;
	return -1;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	int	i1 = sign(point, a, b);
	int	i2 = sign(point, b, c);
	int	i3 = sign(point, c, a);

	if ( i1 == 0 || i2 == 0 || i3 == 0 )
		return false;
	return (i1 == i2) && (i2 == i3);
}
