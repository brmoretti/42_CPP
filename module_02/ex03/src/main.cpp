/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:17:03 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/10 14:23:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point);

int	main( void )
{
	Point	a( 0.0, 0.0 );
	Point	b( 10.0, 30.0 );
	Point	c( 20.0, 0.0 );

	Point	p1( 10.0, 15.0 );
	std::cout << "Inside case: \n" << bsp(a, b, c, p1) << std::endl;
	Point	p2( 30.0, 15.0 );
	std::cout << "Outside case: \n" << bsp(a, b, c, p2) << std::endl;
	Point	p3( 1.0 , 0.0 );
	std::cout << "On edge case: \n" << bsp(a, b, c, p3) << std::endl;
	std::cout << "On vertex case: \n" << bsp(a, b, c, a) << std::endl;

	return 0;
}
