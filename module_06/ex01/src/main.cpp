/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:51:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/30 11:08:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

#include <iostream>
#include <bitset>

int	main(void)
{
	Data	*bart = new Data();

	bart->name = "Bart Simpson";
	bart->age = 10;
	bart->sex = 'M';
	bart->height = 1.21f;
	bart->weight = 38.5554;

	uintptr_t	ptr;

	ptr = Serializer::serialize(bart);

	Data	*perhaps_bart;

	perhaps_bart = Serializer::deserialize(ptr);

	std::cout \
		<< "Deserialized:"
		<< "\nName: " << perhaps_bart->name \
		<< "\nAge: " << perhaps_bart->age \
		<< "\nSex: " << perhaps_bart->sex \
		<< "\nHeight: " << perhaps_bart->height \
		<< "\nWeight: " << perhaps_bart->weight \
	<< std::endl;

	delete perhaps_bart;

	return 0;
}
