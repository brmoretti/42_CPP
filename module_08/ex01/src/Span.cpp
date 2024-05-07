/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 14:22:30 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/07 13:22:55 by bmoretti         ###   ########.fr       */
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
	}
	return *this;
}

void	Span::addNumber(const int & number)
{
	if (this->_n_elements >= this->_size) {
		throw (SpanIsFullException());
	}
	this->_vec[this->_n_elements] = number;
	this->_n_elements++;
}

int		Span::shortestSpan()
{
	if (this->_n_elements <= 1) {
		throw (NotEnoughMembersException());
	}

	int	shortest_span = -1;

	std::sort(this->_vec.begin(), this->_vec.end());
	for (size_t i = 1; i < this->_n_elements; i++) {
		int span = this->_vec[i] - this->_vec[i-1];
		if (span < shortest_span || shortest_span == -1) {
			shortest_span = span;
		}
	}
	return shortest_span;
}

int		Span::longestSpan()
{
	if (this->_n_elements <= 1) {
		throw (NotEnoughMembersException());
	}

	std::sort(this->_vec.begin(), this->_vec.end());

	return this->_vec[_n_elements - 1] - this->_vec[0];
}

void	Span::addRandomNumbers(int n, int max)
{
	if (n <= 0 || max < 0) {
		return;
	}
	for (int i = 0; i < n; i++) {
		int random_number = rand() % max;
		try{
			this->addNumber(random_number);
		}
		catch (Span::SpanIsFullException &e) {
			std::cerr << "Exception Caught: " << e.what() << std::endl;
			break;
		}
	}
}

const char* Span::NotEnoughMembersException::what(void) const throw()
{
	return "NotEnoughMembersException";
}

const char* Span::SpanIsFullException::what(void) const throw()
{
	return "SpanIsFullException";
}
