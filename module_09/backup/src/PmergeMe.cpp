/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:52:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/13 17:36:40 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _alone(-1), _jacobsthal_seq(NULL)
{

}

PmergeMe::~PmergeMe()
{
	if (this->_jacobsthal_seq) {
		delete this->_jacobsthal_seq;
	}
}

PmergeMe::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& rhs)
{
	if (this != &rhs) {
		this->_pairs = rhs._pairs;
	}
	return *this;
}

void		PmergeMe::addElement(const int & nb)
{
	if (this->_alone != -1) {
		std::vector<int>	pair;
		pair.push_back(this->_alone);
		pair.push_back(nb);
		this->_pairs.push_back(pair);
		this->_alone = -1;
		return;
	}
	this->_alone = nb;
}

void	PmergeMe::sortFordJohnson()
{
	this->generateJacobsthalSequence(this->_pairs.size());
	this->sortPairs();
	this->sortPairsBySecondElement();
	this->createMainSequence();
	this->mergePend();
}

void	PmergeMe::generateJacobsthalSequence(const size_t & size)
{
	this->_jacobsthal_seq = new size_t[size];

	if (size == 0) {
		return;
	}
	if (size >= 1) {
		this->_jacobsthal_seq[0] = 0;
	}
	if (size >= 2) {
		this->_jacobsthal_seq[1] = 1;
	}
	for (size_t i = 2; this->_jacobsthal_seq[i - 1] < size; ++i) {
		this->_jacobsthal_seq[i] = \
			this->_jacobsthal_seq[i - 1] + 2 * this->_jacobsthal_seq[i - 2];
	}
}

void	PmergeMe::sortPairs()
{
	v_vectors::iterator			it;
	const v_vectors::iterator	it_end = this->_pairs.end();

	for (it = this->_pairs.begin(); it != it_end; ++it) {
		std::swap((*it)[0], (*it)[1]);
	}
}

bool	compareSecondElement(const std::vector<int>& v1,
		const std::vector<int>& v2) {
	return v1[1] < v2[1];
}

void	PmergeMe::sortPairsBySecondElement() {
	std::sort(this->_pairs.begin(), this->_pairs.end() - 1, compareSecondElement);
}

void	PmergeMe::createMainSequence()
{
	v_vectors::iterator			it;
	const v_vectors::iterator	it_end = this->_pairs.end();

	this->_main.insert(this->_main.end(),
		this->_pairs[0].begin(), this->_pairs[0].end());
	this->_pairs[0].clear();

	for (it = this->_pairs.begin() + 1; it != it_end; ++it) {
		this->_main.push_back((*it).back());
		(*it).pop_back();
	}
}

void	PmergeMe::mergePend()
{
	size_t	jacob_index = 3;
	size_t	i = this->_jacobsthal_seq[jacob_index] - 1;
	bool	ending = false;
	size_t	insertion_index = 1;

	while (!(ending && this->_pairs[i].size() > 0)) {
		if (this->_pairs[i].size() == 0) {
			jacob_index++;
			i = this->_jacobsthal_seq[jacob_index] - 1;
			if (i >= this->_pairs.size()) {
				i = this->_pairs.size() - 1;
				ending = true;
			}
		}
		if (this->_pairs[i].size() == 0) {
			break;
		}
		while (insertion_index >= 1
			&& !(this->_main[insertion_index - 1] < this->_pairs[i][0]
				&& this->_pairs[i][0] < this->_main[insertion_index])) {
			if (this->_pairs[i][0] < this->_main[insertion_index - 1]) {
				insertion_index--;
			} else if (this->_pairs[i][0] > this->_main[insertion_index]) {
				insertion_index++;
			}
		}
		this->_main.insert(this->_main.begin() + insertion_index, this->_pairs[i][0]);
		this->_pairs[i].erase(this->_pairs[i].begin());
		i--;
	}
}
