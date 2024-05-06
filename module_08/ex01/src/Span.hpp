/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 13:44:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/06 19:32:52 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <cmath>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
public:
	Span(const unsigned int & size);
	~Span();
	Span(const Span& rhs);
	Span&	operator=(const Span& rhs);

	void	addNumber(const int & number);
	int		shortestSpan();
	int		longestSpan();

	const unsigned int &	getSize() const;

	class NotEnoughMembersException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

	class SpanIsFullException : public std::exception
	{
	public:
		virtual const char* what(void) const throw();
	};

private:
	const unsigned int	_size;
	unsigned int		_n_elements;
	std::vector<int>	_vec;

};

#endif
