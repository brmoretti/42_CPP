/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:52:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/10 18:35:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{

}

PmergeMe::~PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs) {
		this->pairs = rhs.pairs;
	}
	return *this;
}

void		PmergeMe::addElement(const int & nb)
{
	static short int i = 0;

	if (i == 0) {
		std::vector<int>	pair;
		pair.push_back(nb);
		this->pairs.push_back(pair);
		i++;
		return;
	}
	this->pairs.back().push_back(nb);
	i = 0;
}

void	PmergeMe::sortFordJohnson()
{
	this->sortPairs();
	this->sortPairsBySecondElement();
}

void	PmergeMe::sortPairs()
{
	v_vectors::iterator	it;

	for (it = this->pairs.begin(); it != this->pairs.end(); ++it) {
		if (it->size() == 2 && (*it)[0] > (*it)[1]) {
			std::swap((*it)[0], (*it)[1]);
		}
	}
}
bool	compareSecondElement(const std::vector<int>& v1,
		const std::vector<int>& v2) {
	return v1[1] < v2[1];
}

void	PmergeMe::sortPairsBySecondElement() {
	std::sort(this->pairs.begin(), this->pairs.end() - 1, compareSecondElement);
}

