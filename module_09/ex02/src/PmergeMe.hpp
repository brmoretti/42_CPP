/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 18:50:43 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/10 18:27:04 by bmoretti         ###   ########.fr       */
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
	v_vectors	pairs;

	void	sortPairs();
	void	sortPairsBySecondElement();
	void	_mergeSortRecursevely();

};

#endif
