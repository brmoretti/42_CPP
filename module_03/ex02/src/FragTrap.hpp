/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/13 23:59:41 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string name);
	~FragTrap();
	FragTrap(const FragTrap & rhs);
	FragTrap&	operator=(const FragTrap & rhs);
	
	void	highFivesGuys(void);

private:
	bool				_gate_keeper_mode;
	const static int	HIT_POINTS = 100;
	const static int	ENERGY_POINTS = 100;
	const static int	ATTACK_DAMAGE = 30;
};

#endif