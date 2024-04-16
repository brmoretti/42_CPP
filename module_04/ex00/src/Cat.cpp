/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:07:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 10:47:56 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " constructor called" << std::endl;
	this->setType("Cat");
}

Cat::~Cat()
{
	std::cout << RED << "Cat" << RESET;
	std::cout << " destructor called" << std::endl;
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
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << RED << "Meow>🐈" << RESET << std::endl;
}
