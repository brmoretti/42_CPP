/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 02:28:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/08 14:44:36 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie( std::string name );

void	randomChump( std::string name );

int	main ( void )
{
	Zombie*		mimi = newZombie("MIMI");

	mimi->announce();
	randomChump("LAMBARI");
	delete mimi;
	return 0;
}
