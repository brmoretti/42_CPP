/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:25:59 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/02 13:25:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <list>

#include "easyfind.hpp"

int	main(void)
{
	std::list<int>		lst;

	lst.push_back(0);
	lst.push_back(1);
	lst.push_back(42);
	lst.push_back(42);
	lst.push_back(84);

	std::vector<int>	vec(lst.begin(), lst.end());

	int		returned;
	int		test;

	std::cout << "***VECTOR***" << std::endl;

	test = 0;
	std::cout << "\ntest 0: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 42;
	std::cout << "\ntest 1: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 84;
	std::cout << "\ntest 2: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 1990;
	std::cout << "\ntest 3: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	std::cout << "\n***LIST***" << std::endl;

	test = 0;
	std::cout << "\ntest 0: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 42;
	std::cout << "\ntest 1: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 84;
	std::cout << "\ntest 2: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	test = 1990;
	std::cout << "\ntest 3: find " << test << std::endl;
	returned = easyfind< std::list<int> >(lst, test);
	std::cout << "Returned: " << returned << std::endl;

	return 0;
}
