/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:24:42 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/07 01:58:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
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

void	Harl::insignificant( void )
{
	static int i = 0;

	if (i == 0) {
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		i++;
	}
}

void	Harl::complain( std::string level )
{
	const	std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	while (i < 4 && levels[i].compare(level))
		i++ ;
	switch (i)
	{
	case 0: 
		this->debug();
		//fall through
	case 1: 
		this->info();
		//fall through
	case 2: 
		this->warning();
		//fall through
	case 3: 
		this->error();
		break ;
	default:
		this->insignificant();
	}
}
