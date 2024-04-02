/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:41:48 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/02 00:24:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <chrono>
#include <iomanip>

Account::Account( int initial_deposit ) {
	static int	count_id;

	this->_accountIndex = count_id;
	count_id++;
	if (initial_deposit > 0)
		this->_nbDeposits++;
}

Account::~Account( void ) {
	
}

void	Account::_displayTimestamp( void ) {
	auto now = std::chrono::system_clock::now();
	std::time_t time = std::chrono::system_clock::to_time_t(now);
	std::tm* tm = std::localtime(&time);
	
	std::cout << "[" << std::put_time(tm, "%Y%m%d_%H%M%S") << "]";
}