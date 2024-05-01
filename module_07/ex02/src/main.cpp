/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 13:16:41 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/01 16:18:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{

	{
		std::cout << BOLD("\nArray of Bools size 5") << std::endl;

		Array<bool>	array_bool(5);

		try {
			for (unsigned int i = 0; i < array_bool.size(); i++)
			{
				if (i % 2 == 0) {
					array_bool[i] = true;
				} else {
					array_bool[i] = false;
				}
			}
		}
		catch (std::exception &e) {
			std::cerr << RED("Caught exception: " << e.what()) << std::endl;
		}

		std::cout << array_bool << std::endl;
	}

	{
		std::cout << BOLD("\nArray of Floats size 3") << std::endl;

		Array<float>	array_float(3);

		try {
			for (unsigned int i = 0; i <= array_float.size(); i++)
			{
				array_float[i] = static_cast<float>(i) + 4.2f;
			}
		}
		catch (std::exception &e) {
			std::cerr << RED("Caught exception: " << e.what()) << std::endl;
		}

		std::cout << array_float << std::endl;
	}

	return 0;
}
