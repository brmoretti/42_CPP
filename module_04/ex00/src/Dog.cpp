/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:46 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 10:45:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " constructor called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog()
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " destructor called" << std::endl;
}

Dog::Dog(const Dog & rhs)
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

Dog&	Dog::operator=(const Dog & rhs)
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << YELLOW << "Woof>🐩" << RESET << std::endl;
}
