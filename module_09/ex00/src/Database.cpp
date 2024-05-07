/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:54:06 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/07 17:17:27 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Database.hpp"

Database::Database(std::string& file_path, char sep) : _path(file_path),
														_sep(sep)
{
	std::fstream	file;

	file.open(file_path.c_str(), std::fstream::in);
	if (file.fail()) {
		throw std::runtime_error("Failed to open file");
	}
	std::string	line;
	std::string	date;
	std::string	value_str;

	std::getline(file, line);
	while (std::getline(file, line)) {
		std::istringstream	ss(line);
		std::getline(ss, date, sep);
		std::getline(ss, value_str, sep);
		_map[date] = std::stod(value_str);
	}
}

Database::~Database()
{

}

Database::Database(const Database& rhs)
{

}

Database&	Database::operator=(const Database& rhs)
{

}

Database::Database()
{

}
