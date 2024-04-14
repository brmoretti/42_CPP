/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 13:22:26 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 18:10:17 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

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

	ScavTrap	roque("Roque");

	roque.guardGate();
	popoh.attack("Roque");
	roque.takeDamage(popoh.getAttackDamage());
	roque.beRepaired(50);
	roque.attack("Popó");
	popoh.takeDamage(roque.getAttackDamage());
	popoh.beRepaired(20);

	FragTrap	chapolim("Chapolim");
	chapolim.highFivesGuys();

	DiamondTrap		brabo("Brabo");

	// brabo.whoAmI();
	// brabo.attack("Chapolim");
	// chapolim.takeDamage(brabo.getAttackDamage());

	return 0;
}
