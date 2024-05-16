/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:32:02 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/16 15:07:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << RED("Invalid arguments.\n");
		std::cerr << GREEN("Usage: ./PMergeMe [parameters]\n");
		return (1);
	}

	PMergeMe	merge;
	try
	{
		merge.FordJohnson(argc, argv);
	}
	catch(const std::exception &e)
	{
		std::cerr << RED(e.what()) << std::endl;
	}
	return (0);
}
