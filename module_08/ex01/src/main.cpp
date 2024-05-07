/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:29:19 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/07 13:23:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#include <climits>

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

		sp.addRandomNumbers(1000, 1000000);
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

		sp.addRandomNumbers(1000000, INT_MAX);
		print_spans(sp);
	}

	return 0;
}
