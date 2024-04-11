/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 10:17:03 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/10 16:53:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void )
{
	Fixed			a;
	Fixed const		b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << "\033[1;32m";
	std::cout << "\n###################\n";
	std::cout << "# Aditional tests #";
	std::cout << "\n###################";
	std::cout << "\033[0m" << std::endl;

	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a - b: " << a - b << std::endl;
	std::cout << "b / a: " << b / a << std::endl;
	std::cout << "b / b: " << b / b << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a == a: " << (a == a) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a != a: " << (a != a) << std::endl;
	std::cout << "min( a, b ): " << Fixed::min( a, b ) << std::endl;

	return 0;
}
