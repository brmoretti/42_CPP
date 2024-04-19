/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:01:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/18 16:45:47 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Floor.hpp"

Floor::Floor()
{
	std::cout << "Floor constructor called" << std::endl;
	for (int i = 0;i < 10; i++) {
		this->_spaces[i] = NULL;
	}
}

Floor::~Floor()
{
	std::cout << "Floor destructor called" << std::endl;
	this->clearFloorItems();
}

Floor::Floor(const Floor & rhs)
{
	std::cout << "Floor copy constructor called" << std::endl;
	*this = rhs;
}

Floor&	Floor::operator=(const Floor & rhs)
{
	std::cout << "Floor '=' operator overload called" << std::endl;
	if (this != &rhs) {
		this->cloneFloorItems(rhs);
	}
	return *this;
}

bool	Floor::drop(AMateria *m)
{
	static int	n_dropped = 0;

	while (n_dropped < 10) {
		this->_spaces[n_dropped++] = m;
		std::cout << m->getType() << " dropped" << std::endl;
		return true;
	}
	std::cout << "The floor is full of garbage. Unable to drop";
	std::cout << std::endl;
	return false;
}

void	Floor::clearFloorItems()
{
	for (int i = 0; i < 10; i++) {
		if (this->_spaces[i]) {
			delete this->_spaces[i];
			this->_spaces[i] = NULL;
		}
	}
}

void	Floor::cloneFloorItems(const Floor & floor)
{
	this->clearFloorItems();
	for (int i = 0; i < 10; i++) {
		if (floor._spaces[i]) {
			this->_spaces[i] = floor._spaces[i]->clone();
		}
	}
}
