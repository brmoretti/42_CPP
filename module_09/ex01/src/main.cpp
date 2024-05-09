/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 15:58:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/09 16:08:42 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: ./RPN <string of digits and operators>" \
		<< std::endl;
		return 0;
	}

	try {
		RPN	rpn((std::string(argv[1])));

		rpn.evaluate();
	}
	catch (std::exception & e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
