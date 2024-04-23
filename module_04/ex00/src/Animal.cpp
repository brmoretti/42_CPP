/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:35:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 16:45:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("NONE")
{
	std::cout << BLUE << "Animal" << RESET;
	std::cout << " constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << BLUE << "Animal" << RESET;
	std::cout << " destructor called" << std::endl;
}

Animal::Animal(const Animal & rhs)
{
	std::cout << BLUE << "Animal" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

Animal&	Animal::operator=(const Animal & rhs)
{
	std::cout << BLUE << "Animal" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		if (this->type != rhs.type) {
			std::cout << BLUE << "Animals can't change their's types";
			std::cout << RESET << std::endl;
		}
	}
	return *this;
}

std::string	Animal::getType() const
{
	return this->type;
}

void	Animal::setType(const std::string& type)
{
	this->type = type;
}

void Animal::makeSound() const
{
	std::cout << BLUE << "*Is it you, giraffe?*" << RESET << std::endl;
}
