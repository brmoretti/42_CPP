/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:46 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 18:57:24 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "\033[1;33mDog\033[0m constructor called" << std::endl;
	this->setType("Dog");
}

Dog::~Dog()
{
	std::cout << "\033[1;33mDog\033[0m destructor called" << std::endl;
}

Dog::Dog(const Dog & rhs)
{
	std::cout << "\033[1;33mDog\033[0m copy constructor called";
	std::cout << std::endl;
	*this = rhs;
}

Dog&	Dog::operator=(const Dog & rhs)
{
	std::cout << "\033[1;33mDog\033[0m '=' operator called";
	std::cout << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Woof>🐩" << std::endl;
}
