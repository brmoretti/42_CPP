/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:50:43 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/14 13:45:18 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
# define PMERGE_ME

# include <vector>
# include <deque>
# include <algorithm>
# include <iostream>

class PmergeMe
{
public:
	typedef std::vector< std::vector<int> > v_vectors;
	typedef std::deque< std::deque<int> > d_deque;

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& rhs);
	PmergeMe&	operator=(const PmergeMe& rhs);

	void		addElement(const int & nb);
	void		sortFordJohnson();

private:
	v_vectors			_pairs;
	d_deque				_pairs_deque;
	int					_alone;
	std::vector<int>	_main;
	std::deque<int>		_main_deque;
	size_t				*_jacobsthal_seq;

	void	generateJacobsthalSequence(const size_t & size);
	void	sortPairsVec();
	void	sortPairsDeque();
	void	sortPairsBySecondElementVec();
	void	sortPairsBySecondElementDeque();
	void	createMainSequenceVec();
	void	createMainSequenceDeque();
	size_t	stepBinary(size_t min, size_t max);
	void	mergePendVec();
	void	mergePendDeque();
	void	mergeAloneVec();
	void	mergeAloneDeque();

};

template <typename Pair>
bool compareSecondElement(const Pair& pair1, const Pair& pair2) {
	return pair1[1] < pair2[1];
}

#endif
