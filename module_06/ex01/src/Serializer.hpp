/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:28:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/28 18:47:39 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"

typedef unsigned int* uintptr_t;

class Serializer
{
public:
	~Serializer();

	static uintptr_t	serialize(Data* ptr);
	static Data* 		deserialize(uintptr_t raw);

private:
	Serializer();
	Serializer(const Serializer& rhs);
	Serializer&	operator=(const Serializer& rhs);

};

#endif
