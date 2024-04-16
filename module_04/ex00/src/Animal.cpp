/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:35:18 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 19:00:01 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("NONE")
{
	std::cout << "\033[1;34mAnimal\033[0m constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "\033[1;34mAnimal\033[0m destructor called" << std::endl;
}

Animal::Animal(const Animal & rhs)
{
	std::cout << "\033[1;34mAnimal\033[0m copy constructor called";
	std::cout << std::endl;
	*this = rhs;
}

Animal&	Animal::operator=(const Animal & rhs)
{
	std::cout << "\033[1;34mAnimal\033[0m '=' operator called";
	std::cout << std::endl;
	if (this != &rhs) {
		this->type = rhs.type;
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
	std::cout << "*Is it you, giraffe?*" << std::endl;
}
