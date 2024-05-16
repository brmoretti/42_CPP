/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkValidDate.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:34:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/05/09 11:55:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <stdexcept>
#include <cstdlib>

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
