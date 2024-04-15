/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:26 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 11:56:25 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap	popoh("Popó");
	ClapTrap	klebin("Bambam");

	klebin.attack("Popó");
	popoh.takeDamage(klebin.getAttackDamage());
	popoh.setAttackDamage(20);
	popoh.attack("Bambam");
	klebin.takeDamage(popoh.getAttackDamage());
	klebin.attack("Popó");
	klebin.beRepaired(10);

	ScavTrap roque("Roque");

	std::cout << "--------------x--------------" << std::endl;
	std::cout << "\033[1;32m" << roque.getName() << "\033[0m" << std::endl;
	std::cout << "Attack Damage: " << roque.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << roque.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << roque.getHitPoints() << std::endl;
	std::cout << "--------------x--------------\n" << std::endl;

	roque.guardGate();
	popoh.attack("Roque");
	roque.takeDamage(popoh.getAttackDamage());
	roque.beRepaired(50);
	roque.attack("Popó");
	popoh.takeDamage(roque.getAttackDamage());
	popoh.beRepaired(20);

	return 0;
}
