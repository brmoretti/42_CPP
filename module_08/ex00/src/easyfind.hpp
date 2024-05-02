/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:43:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/02 12:27:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
int	easyfind(T int_container, int int_to_find)
{
	int	pos = 0;

	typename T::const_iterator	it;
	typename T::const_iterator	ite = int_container.end();

	for (it = int_container.begin(); it != ite; ++it) {
		if (*it == int_to_find) {
			std::cout << *it << " found in position " << pos << std::endl;
			return pos;
		}
		pos++;
	}
	std::cout << int_to_find << " not found" << std::endl;
	return -1;
}
