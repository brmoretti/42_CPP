/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:42:19 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 12:13:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "The memory address of the string variable:\n";
	std::cout << &string << "\n";
	std::cout << "The memory address held by stringPTR:\n";
	std::cout << stringPTR << "\n";
	std::cout << "The memory address held by stringREF:\n";
	std::cout << &stringREF << std::endl;

	std::cout << "\nThe value of the string variable:\n";
	std::cout << string << "\n";
	std::cout << "The value pointed to by stringPTR:\n";
	std::cout << *stringPTR << "\n";
	std::cout << "The value pointed to by stringREF:\n";
	std::cout << stringREF << std::endl;

	return 0;
}
