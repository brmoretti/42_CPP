/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:20:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/06 20:03:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template< typename T >
class MutantStack : public std::stack<T>
{
public:
	MutantStack() {};
	~MutantStack() {};
	MutantStack(const MutantStack& rhs) {
		*this = rhs;
	};
	MutantStack&	operator=(const MutantStack& rhs) {
		std::stack< T >::operator=(rhs);
		return *this;
	};

	typedef
		typename std::stack<T>::container_type::iterator
			iterator;

	iterator	begin() {
		return this->c.begin();
	};
	iterator	end() {
		return this->c.end();
	};

	typedef
		typename std::stack<T>::container_type::reverse_iterator
			reverse_iterator;

	reverse_iterator	rbegin() {
		return this->c.rbegin();
	};

	reverse_iterator	rend() {
		return this->c.rend();
	};

};

#endif
