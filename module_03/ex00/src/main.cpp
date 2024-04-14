/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:26 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/13 20:30:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	popoh("Popó");
	ClapTrap	klebin("Bambam");

	klebin.attack("Popó");
	popoh.takeDamage(klebin.getAttackDamage());
	popoh.setAttackDamage(99999999);
	popoh.attack("Bambam");
	klebin.takeDamage(popoh.getAttackDamage());
	klebin.attack("Popó");
	klebin.beRepaired(10);
	for (int i = 0; i < 10; i++) {
		std::cout << popoh.getName() << " is laughing a lot 😂" << std::endl;
		popoh.beRepaired(10);
	}

	return 0;
}