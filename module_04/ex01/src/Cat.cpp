/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:07:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 18:16:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " destructor called" << std::endl;
	delete this->_brain;
}

Cat::Cat(const Cat & rhs)
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

Cat&	Cat::operator=(const Cat & rhs)
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
		*this->_brain = *rhs._brain;
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << RED << "Meow>🐈" << RESET << std::endl;
}

Brain*	Cat::accessBrain() const
{
	return this->_brain;
}

