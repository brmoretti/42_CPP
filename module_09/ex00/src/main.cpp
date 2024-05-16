/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:12:54 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/16 17:03:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cctype>
#include <algorithm>

#include "BitcoinExchange.hpp"


//--- TRIM SPACES ---

bool	notSpace(char c)
{
	return !std::isspace(static_cast<unsigned char>(c));
}

void	trimSpaces(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), notSpace));
	s.erase(std::find_if(s.rbegin(), s.rend(), notSpace).base(), s.end());
}

//--- VALID DATES CHECKER ---

bool	isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool	isValidYear(int year)
{
	return (year > 1000 && year < 3000);
}

bool	isValidMonth(int month)
{
	return (month >= 1 && month <= 12);
}

bool	isValidDay(int year, int month, int day)
{
	if (day < 1 || day > 31) {
		return false;
	}
	if (month == 2) {
		if (isLeapYear(year) && day > 29) {
			return false;
		}
		else if (day > 28) {
			return false;
		}
	}
	if ((month == 4 || month == 6 || month == 9 || month == 11)
		&& day > 30)
	{
		return false;
	}
	return true;
}

bool	checkValidDate(const std::string & date)
{
	int	year, month, day;

	const size_t	firstDash = date.find('-');
	const size_t	secondDash = date.find('-', firstDash + 1);

	if (firstDash == std::string::npos || secondDash == std::string::npos) {
		return false;
	}

	year = std::atoi(date.substr(0, firstDash).c_str());
	month = std::atoi(date.substr(firstDash + 1, secondDash).c_str());
	day = std::atoi(date.substr(secondDash + 1).c_str());

	return (isValidYear(year) && isValidMonth(month)
			&& isValidDay(year, month, day));
}

//--- INPUT FILES ---

void	inputFileLoop(const BitcoinExchange & prices,
	char * file_path, char sep)
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
		BitcoinExchange	prices("data.csv", ',');
		inputFileLoop(prices, argv[1], '|');
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
