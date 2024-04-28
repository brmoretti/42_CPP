/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:43:52 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/28 15:15:20 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& rhs)
{
	*this = rhs;
}

ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void)rhs;
	return *this;
}

void	ScalarConverter::convert(const std::string& literal)
{
	char	c;
	int		i;
	float	f;
	double	d;

	if (literal.length() == 1 && !std::isdigit(literal[0])
		&& std::isprint(literal[0])) {
		f = static_cast<float>(literal[0]);
		d = static_cast<double>(f);
	} else if (literal[literal.length() - 1] == 'f') {
		f = std::atof(literal.c_str());
		d = static_cast<double>(f);
	} else {
		d = std::atof(literal.c_str());
		f = static_cast<float>(d);
	}

	i = static_cast<int>(f);

	if (i < -128 || i > 127) {
		std::cout << "char: impossible";
	} else if (!std::isprint(i)) {
		std::cout << "char: Non displayable";
	} else {
		c = static_cast<char>(i);
		std::cout <<"char : '" << c << "'";
	}

	if (std::isnan(d) || d > INT_MAX || d < INT_MIN) {
		std::cout << "\nint: impossible";
	} else {
		std::cout << "\nint: " << i;
	}
	std::cout << "\nfloat: " << f;
	if (!isinff(f) && (f == std::floor(f) || f == std::ceil(f))) {
		std::cout << ".0";
	}
	std::cout \
		<< "f\ndouble: " << d;
	if (!std::isinf(d) && (d == std::floor(d) || d == std::ceil(d))) {
		std::cout << ".0";
	}
	std::cout << std::endl;
}
