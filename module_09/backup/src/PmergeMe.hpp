/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:50:43 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/13 17:37:00 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGE_ME
# define PMERGE_ME

# include <vector>
# include <algorithm>

class PmergeMe
{
public:
	typedef std::vector< std::vector<int> > v_vectors;

	PmergeMe();
	~PmergeMe();
	PmergeMe(const PmergeMe& rhs);
	PmergeMe&	operator=(const PmergeMe& rhs);

	void		addElement(const int & nb);
	void		sortFordJohnson();

private:
	v_vectors			_pairs;
	int					_alone;
	std::vector<int>	_main;
	size_t				*_jacobsthal_seq;

	void	generateJacobsthalSequence(const size_t & size);
	void	sortPairs();
	void	sortPairsBySecondElement();
	void	createMainSequence();
	void	mergePend();

};

// template <typename Pair>
// bool compareSecondElement(const Pair& pair1, const Pair& pair2) {
// 	return pair1[1] < pair2[1];
// }

#endif
