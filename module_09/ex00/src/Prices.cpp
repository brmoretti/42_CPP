/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Prices.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:54:06 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/08 17:38:59 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Prices.hpp"

void	trimSpaces(std::string& string);

Prices::Prices(const char * file_path, char sep)
{
	std::fstream	file;

	file.open(file_path, std::fstream::in);
	if (file.fail()) {
		throw std::runtime_error("Failed to open data.csv");
	}

	std::string	line;
	std::string	date;
	std::string	value_str;
	double		value;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream	ss(line);
		std::getline(ss, date, sep);
		std::getline(ss, value_str, sep);
		std::istringstream(value_str) >> value;
		this->_map[date] = value;
	}
}

Prices::~Prices()
{
}

Prices::Prices(const Prices& rhs)
{
	*this = rhs;
}

Prices&	Prices::operator=(const Prices& rhs)
{
	if (this != &rhs) {
		this->_map = rhs._map;
	}
	return *this;
}

const double &	Prices::operator[](const char * date) const
{
	std::map<std::string, double>::const_iterator it = this->_map.upper_bound(date);
	if (it == this->_map.begin()) {
		throw std::runtime_error("Invalid date");
	}
	--it;
	return it->second;
}

Prices::Prices()
{

}
