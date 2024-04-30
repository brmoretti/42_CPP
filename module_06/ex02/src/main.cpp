/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 23:08:47 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/30 11:20:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main()
{
	Base*	base;

	std::srand(std::time(NULL));
	for (int i = 0; i < 5; i++) {
		base = generate();
		std::cout << "Pointer:\t";
		identify(base);
		std::cout << "Reference:\t";
		identify(*base);
		std::cout << std::endl;
		delete base;
	}

	return 0;
}
