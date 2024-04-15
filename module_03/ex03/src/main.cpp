/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:26 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/15 11:42:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	FragTrap		chapolim("Chapolim");
	DiamondTrap		brabo("Silvio Santos");

	brabo.whoAmI();
	std::cout << "Attack Damage: " << brabo.getAttackDamage() << std::endl;
	std::cout << "Energy Points: " << brabo.getEnergyPoints() << std::endl;
	std::cout << "Hit Points: " << brabo.getHitPoints() << std::endl;
	brabo.guardGate();
	brabo.beRepaired(10);
	brabo.highFivesGuys();
	brabo.attack("Chapolim");
	chapolim.takeDamage(brabo.getAttackDamage());

	return 0;
}
