/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:24:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/07 02:03:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl( void )
{
}

Harl::~Harl()
{
}

void	Harl::debug( void )
{
	std::cout << "\033[32m" << DEBUG_MSG << "\033[0m" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "\033[35m" << INFO_MSG << "\033[0m" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "\033[33m" << WARNING_MSG << "\033[0m" << std::endl;
}

void	Harl::error( void )
{
	std::cout << "\033[31m" << ERROR_MSG << "\033[0m" << std::endl;
}

void	Harl::complain( std::string level )
{
	const std::string	levels[] = { "DEBUG", "INFO", "WARNING", "ERROR"};
	void				(Harl::*functions[])() = { &Harl::debug, &Harl::info,
							&Harl::warning, &Harl::error };
	int i = 0;
	while (i < 4 && levels[i].compare(level))
		i++ ;
	if (i < 4)
		(this->*functions[i])();
}
