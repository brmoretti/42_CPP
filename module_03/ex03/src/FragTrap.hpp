/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 17:24:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
public:
	FragTrap();
	FragTrap(const std::string name);
	~FragTrap();
	FragTrap(const FragTrap & rhs);
	FragTrap&	operator=(const FragTrap & rhs);

	void	highFivesGuys(void);

protected:
	const static int	HIT_POINTS = 100;
	const static int	ENERGY_POINTS = 100;
	const static int	ATTACK_DAMAGE = 30;
};

#endif
