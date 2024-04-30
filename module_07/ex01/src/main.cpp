/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:45:34 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/30 19:20:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"
#include "other_templates.hpp"
#include "define_colors.hpp"

int	main(void)
{
	int		array_ints[] = {1, 2, 3};
	char	array_chars[] = {'a', 'b', 'c'};
	float	array_floats[] = {1.5f, 2.2f, 3.2f};

	std::cout << BOLD("\nINTS") << std::endl;
	::iter(array_ints, 3, ::add_one<int>);
	std::cout << std::endl;
	::iter(array_ints, 3, ::print<int>);
	std::cout << std::endl;
	::iter(array_ints, 3, ::print_squared<int>);

	std::cout << BOLD("\nCHARS") << std::endl;
	::iter(array_chars, 3, ::add_one<char>);
	std::cout << std::endl;
	::iter(array_chars, 3, ::print<char>);
	std::cout << std::endl;
	::iter(array_chars, 3, ::print_squared<char>);

	std::cout << BOLD("\nFLOATS") << std::endl;
	::iter(array_floats, 3, ::add_one<float>);
	std::cout << std::endl;
	::iter(array_floats, 3, ::print<float>);
	std::cout << std::endl;
	::iter(array_floats, 3, ::print_squared<float>);

	return 0;
}
