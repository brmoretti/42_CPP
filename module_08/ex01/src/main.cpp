/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:29:19 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/06 19:53:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Span.hpp"

#include <cstdlib> // for rand() function
#include <climits> // for INT_MIN and INT_MAX constants

static void	print_spans(Span& span)
{
	try {
		int	shortest = span.shortestSpan();
		std::cout << "Shortest: " << shortest << std::endl;
	}
	catch (Span::NotEnoughMembersException &e) {
		std::cerr << "Exception Caught: " << e.what() << std::endl;
	}
	try {
		int	longest = span.longestSpan();
		std::cout << "Longest: " << longest << std::endl;
	}
	catch (Span::NotEnoughMembersException &e) {
		std::cerr << "Exception Caught: " << e.what() << std::endl;
	}
}

int main(void)
{
	srand(time(0));

	std::cout << "***SUBJECT TEST***" << std::endl;
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

	std::cout << "\n***OVERFLOW TEST***" << std::endl;
	{
		Span	sp = Span(100);

		for (int i = 0; i < 1000; i++) {
			int randomNumber = rand() % 100000 - 100000 / 2;
			try{
				sp.addNumber(randomNumber);
			}
			catch (Span::SpanIsFullException &e)
			{
				std::cerr << "Exception Caught: " << e.what() << std::endl;
				break;
			}
		}
		print_spans(sp);
	}

	std::cout << "\n***ONE MEMBER TEST***" << std::endl;
	{
		Span	sp = Span(5);

		sp.addNumber(42);

		print_spans(sp);
	}

	std::cout << "\n***NO MEMBER TEST***" << std::endl;
	{
		Span	sp = Span(5);

		print_spans(sp);
	}

	std::cout << "\n***ONE MILLION MEMBERS TEST***" << std::endl;
	{
		Span	sp = Span(1000000);

		for (int i = 0; i < 1000000; i++) {
			int randomNumber = rand();
			sp.addNumber(randomNumber);
		}
		print_spans(sp);
	}

	return 0;
}
