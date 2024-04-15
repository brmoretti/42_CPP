/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:26 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 11:54:50 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	popoh("Popó");
	ClapTrap	klebin("Bambam");

	std::cout << "--------------x--------------" << std::endl;
	std::cout << "\033[1;32m" << popoh.getName() << "\033[0m" << std::endl;
	std::cout << "Attack Damage: " << popoh.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << popoh.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << popoh.getHitPoints() << std::endl;
	std::cout << "--------------x--------------\n" << std::endl;

	std::cout << "--------------x--------------" << std::endl;
	std::cout << "\033[1;32m" << klebin.getName() << "\033[0m" << std::endl;
	std::cout << "Attack Damage: " << klebin.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << klebin.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << klebin.getHitPoints() << std::endl;
	std::cout << "--------------x--------------\n" << std::endl;

	klebin.attack("Popó");
	popoh.takeDamage(klebin.getAttackDamage());
	std::cout << "Bambam is focusing!" << std::endl;
	popoh.setAttackDamage(99999999);
	popoh.attack("Bambam");
	klebin.takeDamage(popoh.getAttackDamage());
	klebin.attack("Popó");
	klebin.beRepaired(10);
	for (int i = 0; i < 10; i++) {
		std::cout << popoh.getName() << " is laughing a lot 😂" << std::endl;
		popoh.beRepaired(10);
	}

	std::cout << "--------------x--------------" << std::endl;
	std::cout << "\033[1;32m" << popoh.getName() << "\033[0m" << std::endl;
	std::cout << "Attack Damage: " << popoh.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << popoh.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << popoh.getHitPoints() << std::endl;
	std::cout << "--------------x--------------\n" << std::endl;

	std::cout << "--------------x--------------" << std::endl;
	std::cout << "\033[1;32m" << klebin.getName() << "\033[0m" << std::endl;
	std::cout << "Attack Damage: " << klebin.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << klebin.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << klebin.getHitPoints() << std::endl;
	std::cout << "--------------x--------------\n" << std::endl;

	return 0;
}
