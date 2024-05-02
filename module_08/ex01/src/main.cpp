/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:29:19 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/02 17:02:41 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <cstdlib> // for rand() function
#include <climits> // for INT_MIN and INT_MAX constants

int main(void)
{
	srand(time(0));

	{
		Span	sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		Span	sp = Span(10000);

		for (int i = 0; i < 10000; i++) {
			int randomNumber = rand() % 1000000000;
			sp.addNumber(randomNumber);
		}
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}


	{
		Span	sp = Span(100);

		for (int i = 0; i < 10; i++) {
			int randomNumber = rand() % 100000 - 100000 / 2;
			sp.addNumber(randomNumber);
			std::cout << randomNumber << " ";
		}
		std::cout << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	return 0;
}
