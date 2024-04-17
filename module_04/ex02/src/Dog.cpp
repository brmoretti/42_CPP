/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:46 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 12:06:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::~Dog()
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " destructor called" << std::endl;
	delete this->_brain;
}

Dog::Dog(const Dog & rhs)
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = rhs;
}

Dog&	Dog::operator=(const Dog & rhs)
{
	std::cout << YELLOW << "Dog" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		*this->_brain = *rhs._brain;
	}
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << YELLOW << "Woof>🐩" << RESET << std::endl;
}

Brain*	Dog::accessBrain() const
{
	return this->_brain;
}
