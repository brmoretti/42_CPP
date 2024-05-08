/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:12:54 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/08 17:55:20 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Prices.hpp"

bool	checkValidDate(const std::string & date);
void	trimSpaces(std::string& s);

void	inputFileLoop(const Prices & prices, char * file_path, char sep)
{
	std::fstream	file;

	file.open(file_path, std::fstream::in);
	if (file.fail()) {
		throw std::runtime_error("Failed to open file");
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
		trimSpaces(date);
		if (!checkValidDate(date)) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		trimSpaces(value_str);
		std::istringstream(value_str) >> value;
		if (value < 0.0) {
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000.0) {
			std::cout << "Error: too large number." << std::endl;
			continue;
		}
		try {
			std::cout << date << " => " << value << " = " \
			<< value * prices[date.c_str()] << std::endl;
		}
		catch (std::runtime_error &e) {
			std::cout << e.what() << std::endl;
		}
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2) {
		std::cout << "Usage: ./btc <file>" << std::endl;
		return 0;
	}
	(void)argv;

	try {
		Prices	prices("data.csv", ',');
		inputFileLoop(prices, argv[1], '|');
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
