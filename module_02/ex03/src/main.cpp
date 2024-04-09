/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:17:03 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/09 15:52:20 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	Point a( 0.0, 0.0 );
	Point b( 10.0, 30.0 );
	Point c( 20.0, 0.0 );
	Point p1( 10.0, 15.0 );
	Point p2( 30.0, 15.0 );

	std::cout << "Case 1: " << bsp(a, b, c, p1) << std::endl;
	std::cout << "Case 2: " << bsp(a, b, c, p2) << std::endl;

	return 0;
}
