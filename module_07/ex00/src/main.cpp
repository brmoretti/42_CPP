/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:07:45 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/01 16:23:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

int	main(void)
{
	{
		std::cout << "\n*** INT ***\n" << std::endl;

		int	x = 10;
		int	y = 20;

		std::cout << "SWAP TEST";
		swap<int>(x, y);
		std::cout << "\nx:\t" << x << "\ny:\t" << y << std::endl;

		std::cout << "\nMIN TEST";
		std::cout \
			<< "\nmin:\t" << min<int>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&min:\t" << &(min<int>(x, y)) << std::endl;

		std::cout << "\nMAX TEST";
		std::cout \
			<< "\nmax:\t" << max<int>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&max:\t" << &(max<int>(x, y)) << std::endl;

		std::cout << "\n*******\n x = y \n*******" << std::endl;
		x = y;

		std::cout << "\nMIN TEST EQUAL VALUES";
		std::cout \
			<< "\nmin:\t" << min<int>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&min:\t" << &(min<int>(x, y)) << std::endl;

		std::cout << "\nMAX TEST EQUAL VALUES";
		std::cout \
			<< "\nmax:\t" << max<int>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&max:\t" << &(max<int>(x, y)) << std::endl;
	}

	{
		std::cout << "\n*** FLOAT ***\n" << std::endl;

		float	x = 4.2;
		float	y = 42.42;

		std::cout << "SWAP TEST";
		swap<float>(x, y);
		std::cout << "\nx:\t" << x << "\ny:\t" << y << std::endl;

		std::cout << "\nMIN TEST";
		std::cout \
			<< "\nmin:\t" << min<float>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&min:\t" << &(min<float>(x, y)) << std::endl;

		std::cout << "\nMAX TEST";
		std::cout \
			<< "\nmax:\t" << max<float>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&max:\t" << &(max<float>(x, y)) << std::endl;

		std::cout << "\n*******\n x = y \n*******" << std::endl;
		x = y;

		std::cout << "\nMIN TEST EQUAL VALUES";
		std::cout \
			<< "\nmin:\t" << min<float>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&min:\t" << &(min<float>(x, y)) << std::endl;

		std::cout << "\nMAX TEST EQUAL VALUES";
		std::cout \
			<< "\nmax:\t" << max<float>(x, y) \
			<< "\n&x:\t" << &x << "\n&y:\t" << &y \
			<< "\n&max:\t" << &(max<float>(x, y)) << std::endl;
	}

	{
		std::cout << "\n*** SUBJECT MAIN ***\n" << std::endl;

		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

		std::string c = "chaine1";
		std::string d = "chaine2";

		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	return 0;
}
