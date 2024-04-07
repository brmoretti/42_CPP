/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 15:24:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/07 01:47:19 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>
# include <string>

# define DEBUG_MSG "[DEBUG]\nI love having extra bacon for my " \
	"7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"

# define INFO_MSG "[INFO]\nI cannot believe adding extra bacon costs more " \
	"money. You didn’t put enough bacon in my burger! " \
	"If you did, I wouldn’t be asking for more!"

# define WARNING_MSG "[WARNING]\nI think I deserve to have some extra " \
	"bacon for free. I’ve been coming for years whereas you started " \
	"working here since last month."

# define ERROR_MSG "[ERROR]\nThis is unacceptable! " \
	"I want to speak to the manager now."

# define INSIGNIFICANT_MSG "[ Probably complaining about insignificant" \
	"problems ]"

class Harl
{
private:
	void	debug( void );
	void	info( void );
	void	warning( void );
	void	error( void );
	void	insignificant( void );

public:
	Harl();
	~Harl();

	void	complain( std::string level );
};

#endif
