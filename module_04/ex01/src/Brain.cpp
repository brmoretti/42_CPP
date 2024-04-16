/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:57:56 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:54 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << CYAN << "Brain" << RESET;
	std::cout << " constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << CYAN << "Brain" << RESET;
	std::cout << " destructor called" << std::endl;
}

Brain::Brain(const Brain & rhs)
{
	std::cout << CYAN << "Brain" << RESET;
	std::cout << " copy constructor called" << std::endl;
	*this = rhs;
}

Brain&	Brain::operator=(const Brain & rhs)
{
	std::cout << CYAN << "Brain" << RESET;
	std::cout << " '=' operator called" << std::endl;
	if (this != &rhs) {
		for (int i = 0; i < N_IDEAS; i++) {
			this->_ideas[i] = rhs._ideas[i];
		}
	}
	return *this;
}

const std::string	Brain::getIdea(const int & idea_index) const
{
	if (idea_index < 0 || idea_index >= N_IDEAS)
		return "*blurry toughts*";
	return this->_ideas[idea_index];
}

void	Brain::setIdea(const int & idea_index, const std::string & idea)
{
	if (idea_index < 0 || idea_index >= N_IDEAS)
		std::cout << "Index is out of this mind comprehension..." << std::endl;
	this->_ideas[idea_index] = idea;
}

