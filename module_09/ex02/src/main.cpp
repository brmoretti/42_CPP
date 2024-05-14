/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 14:34:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/14 15:27:44 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char *argv[])
{
	std::vector<int>	inputs;

	if (argc > 1) {
		for (int i = 1; i < argc; i++) {
			int	j;
			j = std::atoi(argv[i]);
			if (j < 0) {
				std::cout << "Error" << std::endl;
				return 0;
			}
			inputs.push_back(j);
		}
	} else {
		return 0;
	}

	std::sort(inputs.begin(), inputs.end());
	std::vector<int>::iterator it = std::unique(inputs.begin(), inputs.end());
	if (it != inputs.end()) {
		std::cout << "Error: Duplicate values in inputs vector" << std::endl;
		return 0;
	}

	PmergeMe		fj;

	std::cout << "Before: ";





	fj.sortFordJohnson();


	return (0);
}
