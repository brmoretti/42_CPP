/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:18:57 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/01 17:05:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

# include "define_colors.hpp"

template <typename T>
class Array
{
public:
	Array();
	Array(const unsigned int & n);
	~Array();
	Array(const Array& rhs);

	unsigned int	size() const;

	Array&	operator=(const Array& rhs);
	T&		operator[](const unsigned int & index) const;
	T&		operator[](const unsigned int & index);

private:
	T*					_array;
	unsigned int		_size;

};

template <typename T>
std::ostream&	operator<<(std::ostream& lhs, const Array<T> & rhs);

# include "Array.tpp"

#endif
