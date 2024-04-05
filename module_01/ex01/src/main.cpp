/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:47:00 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 11:26:32 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name );

int	main( void )
{
	int		n = 5;
	Zombie	*horde = zombieHorde(n, "MIMI");

	while (n)
		horde[--n].announce();
	delete [] horde;
}
