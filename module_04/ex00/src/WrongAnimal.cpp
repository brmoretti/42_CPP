/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:04:07 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 16:45:10 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("NONE")
{
	std::cout << BLUE << "WrongAnimal" << RESET;
	std::cout << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << BLUE << "WrongAnimal" << RESET;
	std::cout << " destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal & rhs)
{
	std::cout << BLUE << "WrongAnimal" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal & rhs)
{
	std::cout << BLUE << "WrongAnimal" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		if (this->type != rhs.type) {
			std::cout << BLUE << "Animals can't change their's types";
			std::cout << RESET << std::endl;
		}
	}
	return *this;
}

std::string	WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::setType(const std::string& type)
{
	this->type = type;
}

void WrongAnimal::makeSound() const
{
	std::cout << BLUE << "*Is it you, giraffe?*" << RESET << std::endl;
}
