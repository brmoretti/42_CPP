/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 23:26:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/28 15:21:16 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTE_HPP
# define SCALARCONVERTE_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>

class ScalarConverter
{
public:
	~ScalarConverter();
	static void	convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter & rhs);
	ScalarConverter&	operator=(const ScalarConverter & rhs);

};

#endif
