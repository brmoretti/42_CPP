/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 13:52:14 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/14 13:49:31 by bmoretti         ###   ########.fr       */
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
		this->_pairs.push_back(std::vector<int>());
		this->_pairs.back().push_back(this->_alone);
		this->_pairs.back().push_back(nb);

		this->_pairs_deque.push_back(std::deque<int>());
		this->_pairs_deque.back().push_back(this->_alone);
		this->_pairs_deque.back().push_back(nb);

		this->_alone = -1;
		return;
	}
	this->_alone = nb;
}

void	PmergeMe::sortFordJohnson()
{
	this->generateJacobsthalSequence(this->_pairs.size());

	this->sortPairsVec();
	this->sortPairsBySecondElementVec();
	this->createMainSequenceVec();
	this->mergePendVec();
	if (this->_alone >= 0) {
		this->mergeAloneVec();
	}

	this->sortPairsDeque();
	this->sortPairsBySecondElementDeque();
	this->createMainSequenceDeque();
	this->mergePendDeque();
	if (this->_alone >= 0) {
		this->mergeAloneDeque();
	}
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
	int	i;
	for (i = 2; this->_jacobsthal_seq[i - 1] < size; ++i) {
		this->_jacobsthal_seq[i] = \
			this->_jacobsthal_seq[i - 1] + 2 * this->_jacobsthal_seq[i - 2];
	}
	this->_jacobsthal_seq[i] = \
	this->_jacobsthal_seq[i - 1] + 2 * this->_jacobsthal_seq[i - 2];
}

void	PmergeMe::sortPairsVec()
{
	v_vectors::iterator			it;
	const v_vectors::iterator	it_end = this->_pairs.end();

	for (it = this->_pairs.begin(); it != it_end; ++it) {
		if ((*it)[0] > (*it)[1]) {
			std::swap((*it)[0], (*it)[1]);
		}
	}
}

void	PmergeMe::sortPairsDeque()
{
	d_deque::iterator			it;
	const d_deque::iterator	it_end = this->_pairs_deque.end();

	for (it = this->_pairs_deque.begin(); it != it_end; ++it) {
		if ((*it)[0] > (*it)[1]) {
			std::swap((*it)[0], (*it)[1]);
		}
	}
}

void	PmergeMe::sortPairsBySecondElementVec() {
	std::sort(this->_pairs.begin(),
		this->_pairs.end(),
			compareSecondElement<v_vectors::value_type>);
}

void	PmergeMe::sortPairsBySecondElementDeque()
{
	std::sort(this->_pairs_deque.begin(),
		this->_pairs_deque.end(),
			compareSecondElement<d_deque::value_type>);
}

void	PmergeMe::createMainSequenceVec()
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

void	PmergeMe::createMainSequenceDeque()
{
	d_deque::iterator			it;
	const d_deque::iterator		it_end = this->_pairs_deque.end();

	this->_main_deque.insert(this->_main_deque.end(),
		this->_pairs_deque[0].begin(), this->_pairs_deque[0].end());
	this->_pairs_deque[0].clear();

	for (it = this->_pairs_deque.begin() + 1; it != it_end; ++it) {
		this->_main_deque.push_back((*it).back());
		(*it).pop_back();
	}
}

size_t	PmergeMe::stepBinary(size_t min, size_t max)
{
	size_t	step = (max - min) / 2;

	if (step == 0) {
		step = 1;
	}
	return step;
}

void	PmergeMe::mergePendVec()
{
	size_t	jacob_index = 3;
	size_t	i = this->_jacobsthal_seq[jacob_index] - 1;
	bool	ending = false;
	size_t	insertion_index;
	size_t	max_inserted_index = 2;

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
		insertion_index = max_inserted_index / 2;
		while (insertion_index >= 1
			&& !(this->_main[insertion_index - 1] < this->_pairs[i][0]
				&& this->_pairs[i][0] < this->_main[insertion_index])) {
			if (this->_pairs[i][0] < this->_main[insertion_index - 1]) {
				insertion_index -= this->stepBinary(0, insertion_index);
			} else if (this->_pairs[i][0] > this->_main[insertion_index]) {
				insertion_index += this->stepBinary(insertion_index, max_inserted_index);
			}
			if (insertion_index > max_inserted_index) {
				max_inserted_index = insertion_index;
			}
		}
		this->_main.insert(this->_main.begin() + insertion_index, this->_pairs[i][0]);
		this->_pairs[i].erase(this->_pairs[i].begin());
		i--;
	}
}

void	PmergeMe::mergePendDeque()
{
	size_t	jacob_index = 3;
	size_t	i = this->_jacobsthal_seq[jacob_index] - 1;
	bool	ending = false;
	size_t	insertion_index;
	size_t	max_inserted_index = 2;

	while (!(ending && this->_pairs_deque[i].size() > 0)) {
		if (this->_pairs_deque[i].size() == 0) {
			jacob_index++;
			i = this->_jacobsthal_seq[jacob_index] - 1;
			if (i >= this->_pairs_deque.size()) {
				i = this->_pairs_deque.size() - 1;
				ending = true;
			}
		}
		if (this->_pairs_deque[i].size() == 0) {
			break;
		}
		insertion_index = max_inserted_index / 2;
		while (insertion_index >= 1
			&& !(this->_main_deque[insertion_index - 1] < this->_pairs_deque[i][0]
				&& this->_pairs_deque[i][0] < this->_main_deque[insertion_index])) {
			if (this->_pairs_deque[i][0] < this->_main_deque[insertion_index - 1]) {
				insertion_index -= this->stepBinary(0, insertion_index);
			} else if (this->_pairs_deque[i][0] > this->_main_deque[insertion_index]) {
				insertion_index += this->stepBinary(insertion_index, max_inserted_index);
			}
			if (insertion_index > max_inserted_index) {
				max_inserted_index = insertion_index;
			}
		}
		this->_main_deque.insert(this->_main_deque.begin() + insertion_index, this->_pairs_deque[i][0]);
		this->_pairs_deque[i].pop_front();
		i--;
	}
}

void	PmergeMe::mergeAloneVec()
{
	size_t	insertion_index;
	size_t	max_inserted_index = this->_main.size();

	insertion_index = max_inserted_index / 2;
	while ((insertion_index >= 1 && insertion_index < this->_main.size())
		&& !(this->_main[insertion_index - 1] < this->_alone
			&& this->_alone < this->_main[insertion_index])) {
		if (this->_alone < this->_main[insertion_index - 1]) {
			insertion_index -= this->stepBinary(0, insertion_index);
		} else if (this->_alone > this->_main[insertion_index]) {
			insertion_index += this->stepBinary(insertion_index, max_inserted_index);
		}
		if (insertion_index > max_inserted_index) {
			max_inserted_index = insertion_index;
		}
	}
	this->_main.insert(this->_main.begin() + insertion_index, this->_alone);
}
void	PmergeMe::mergeAloneDeque()
{
	size_t	insertion_index;
	size_t	max_inserted_index = this->_main_deque.size();

	insertion_index = max_inserted_index / 2;
	while ((insertion_index >= 1 && insertion_index < this->_main_deque.size())
		&& !(this->_main_deque[insertion_index - 1] < this->_alone
			&& this->_alone < this->_main_deque[insertion_index])) {
		if (this->_alone < this->_main_deque[insertion_index - 1]) {
			insertion_index -= this->stepBinary(0, insertion_index);
		} else if (this->_alone > this->_main_deque[insertion_index]) {
			insertion_index += this->stepBinary(insertion_index, max_inserted_index);
		}
		if (insertion_index > max_inserted_index) {
			max_inserted_index = insertion_index;
		}
	}
	this->_main_deque.insert(this->_main_deque.begin() + insertion_index, this->_alone);
}
