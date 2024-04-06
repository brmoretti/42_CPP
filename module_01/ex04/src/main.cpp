/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:58:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/06 14:09:01 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SedIsForLosers.hpp"

int	main( int argc, char *argv[] )
{
	if (argc != 4) {
		std::cerr << "Usage: ./SedIsForLosers <filename> <s1> <s2>"
			<< std::endl;
		return 1;
	}
	NewSed	new_sed(argv[1], argv[2], argv[3]);
	return 0;
}
