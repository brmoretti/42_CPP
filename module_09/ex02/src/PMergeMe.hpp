/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:29:11 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/16 13:46:25 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <sstream>
# include <cstdlib>
# include <algorithm>
# include <ctime>
# include <typeinfo>
# include <cstring>

# define BLUE(text) "\033[34m" << text << "\033[0m"
# define RED(text) "\033[31m" << text << "\033[0m"
# define GREEN(text) "\033[32m" << text << "\033[0m"
# define YELLOW(text) "\033[33m" << text << "\033[0m"
# define MAGENTA(text) "\033[35m" << text << "\033[0m"
# define CYAN(text) "\033[36m" << text << "\033[0m"

class PMergeMe
{
	private:
		int					straggler;
		int					numberOfElements;
		std::vector<int>	sortedVector;
		std::vector<int>	unsortedVector;
		std::vector<int>	pendChainVector;
		std::deque<int>		sortedDeque;
		std::deque<int>		unsortedDeque;
		std::deque<int>		pendChainDeque;
		std::vector<int>	sortedCompVector;
		std::vector<int>	unsortedCompVector;
		std::vector<int>	pendChainCompVector;
		std::deque<int>		sortedCompDeque;
		std::deque<int>		unsortedCompDeque;
		std::deque<int>		pendChainCompDeque;
	public:
		PMergeMe(void);
		PMergeMe(const PMergeMe &merge);
		PMergeMe &operator=(const PMergeMe &merge);
		~PMergeMe(void);
		void				FordJohnson(int argc, char **argv);
		void				populateContainers(int argc, char **argv);
		void				createAndSortMainChainVector(void);
		void				createAndSortMainChainCompVector(void);
		void				createAndSortMainChainDeque(void);
		void				createAndSortMainChainCompDeque(void);
		void				insertionVector(void);
		void				insertionDeque(void);
		void				insertionCompVector(void);
		void				insertionCompDeque(void);
};

template <typename T>
void	foundStraggler(T &container, int &straggler)
{
	typename T::iterator	itStraggler;

	if (container.size() % 2)
	{
		itStraggler = container.end();
		itStraggler--;
		straggler = *itStraggler;
		container.pop_back();
	}
	return ;
}

template <typename T>
void	printMessage(T sorted, std::string type)
{
	typename T::iterator	it = sorted.begin();
	typename T::iterator	itEnd = sorted.end();

	std::cout << GREEN("After (" << type << "):\t");
	for (; it != itEnd; it++)
		std::cout << *it << (it != itEnd - 1 ? " " : "\n");
	return ;
}

#endif
