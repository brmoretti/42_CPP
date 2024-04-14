/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/13 23:34:23 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string name);
	~ScavTrap();
	ScavTrap(const ScavTrap & rhs);
	ScavTrap&	operator=(const ScavTrap & rhs);
	
	void	guardGate();
	void	attack(const std::string& target);

private:
	bool				_gate_keeper_mode;
	const static int	HIT_POINTS = 100;
	const static int	ENERGY_POINTS = 50;
	const static int	ATTACK_DAMAGE = 20;
};

#endif