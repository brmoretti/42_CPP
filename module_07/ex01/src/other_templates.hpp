/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_templates.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:29:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/30 17:45:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void	add_one(T& x)
{
	std::cout << "add_one called" << std::endl;
	x += 1;
}

template <typename T>
void	print(const T & x)
{
	std::cout << "print called" << std::endl;
	std::cout << x << std::endl;
}

template <typename T>
void	print_squared(const T & x)
{
	std::cout << "print_squared called" << std::endl;
	std::cout << x * x << std::endl;
}
