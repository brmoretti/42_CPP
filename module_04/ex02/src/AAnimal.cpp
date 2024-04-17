/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:53:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 12:12:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::~AAnimal()
{
	std::cout << BLUE << "AAnimal" << RESET;
	std::cout << " destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=(const AAnimal & rhs)
{
	std::cout << BLUE << "AAnimal" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
	}
	return *this;
}

std::string	AAnimal::getType() const
{
	return this->type;
}

void	AAnimal::setType(const std::string& type)
{
	this->type = type;
}

