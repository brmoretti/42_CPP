/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:07:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 18:57:30 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "\033[1;31mCat\033[0m constructor called" << std::endl;
	this->setType("Cat");
}

Cat::~Cat()
{
	std::cout << "\033[1;31mCat\033[0m destructor called" << std::endl;
}

Cat::Cat(const Cat & rhs)
{
	std::cout << "\033[1;31mCat\033[0m copy constructor called";
	std::cout << std::endl;
	*this = rhs;
}

Cat&	Cat::operator=(const Cat & rhs)
{
	std::cout << "\033[1;31mCat\033[0m '=' operator called";
	std::cout << std::endl;
	if (this != &rhs) {
		Animal::operator=(rhs);
	}
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Meow>🐈" << std::endl;
}
