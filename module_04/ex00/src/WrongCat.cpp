/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:07:01 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 11:07:05 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << RED << "WrongCat" << RESET;
	std::cout << " constructor called" << std::endl;
	this->setType("WrongCat");
}

WrongCat::~WrongCat()
{
	std::cout << RED << "WrongCat" << RESET;
	std::cout << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat & rhs)
{
	std::cout << RED << "WrongCat" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

WrongCat&	WrongCat::operator=(const WrongCat & rhs)
{
	std::cout << RED << "WrongCat" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		WrongAnimal::operator=(rhs);
	}
	return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << RED << "Meow>🐈" << RESET << std::endl;
}
