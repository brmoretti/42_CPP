/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 11:53:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 16:45:06 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("NONE")
{
	std::cout << BLUE << "Animal" << RESET;
	std::cout << " constructor called" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << BLUE << "AAnimal" << RESET;
	std::cout << " destructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal & rhs)
{
	std::cout << BLUE << "AAnimal" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

AAnimal&	AAnimal::operator=(const AAnimal & rhs)
{
	std::cout << BLUE << "AAnimal" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		if (this->type != rhs.type) {
			std::cout << BLUE << "Animals can't change their's types";
			std::cout << RESET << std::endl;
		}
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
