/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 11:43:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/06 19:14:35 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T int_container, int int_to_find)
{
	typename T::const_iterator	begin = int_container.begin();
	typename T::const_iterator	end = int_container.end();
	typename T::const_iterator	it = std::find(begin, end, int_to_find);

	if (it != int_container.end()) {
		int pos = std::distance(begin, it);
		std::cout << *it << " found in position " << pos << std::endl;
		return pos;
	} else {
		std::cout << int_to_find << " not found" << std::endl;
		return -1;
	}
}
