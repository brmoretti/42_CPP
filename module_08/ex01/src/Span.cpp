/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:22:30 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/02 16:46:13 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(const unsigned int & size) : _size(size),
										_n_elements(0),
										_vec(size)

{
}

Span::~Span()
{
}

Span::Span(const Span& rhs) : _size(rhs._size)
{
	*this = rhs;
}

Span&	Span::operator=(const Span& rhs)
{
	if (this != &rhs) {
		const_cast<unsigned int&>(_size) = rhs._size;
		this->_n_elements = rhs._n_elements;
		this->_vec = rhs._vec;
		this->_min = rhs._min;
		this->_max = rhs._max;
		this->_shortest_span = rhs._shortest_span;
	}
	return *this;
}

void	Span::addNumber(const int & number)
{
	if (this->_n_elements >= this->_size) {
		throw (SpanIsFullException());
	}
	this->_vec[this->_n_elements] = number;
	if (this->_n_elements == 0) {
		this->_min = number;
		this->_max = number;
	} else if (this->_n_elements == 1) {
		this->_shortest_span = std::abs(this->_vec[0] - this->_vec[1]);
	}
	if (number > this->_max) {
		this->_max = number;
	} else if (number < this->_min) {
		this->_min = number;
	}
	if (this->_n_elements > 1) {
		std::vector<int>::const_iterator	it = this->_vec.begin();
		std::vector<int>::const_iterator	it_end = it + this->_n_elements;
		int	span;
		while (it != it_end) {
			span = std::abs(*it - *it_end);
			if (span < this->_shortest_span) {
				this->_shortest_span = span;
			}
			it++;
		}
	}
	this->_n_elements++;
}

int		Span::shortestSpan()
{
	if (this->_n_elements <= 1) {
		throw (OneMemberException());
	}
	return this->_shortest_span;
}

int		Span::longestSpan()
{
	return this->_max - this->_min;
}

const unsigned int &	Span::getSize() const
{
	return this->_size;
}

const char* Span::OneMemberException::what(void) const throw()
{
	return "OneMemberException";
}

const char* Span::SpanIsFullException::what(void) const throw()
{
	return "SpanIsFullException";
}
