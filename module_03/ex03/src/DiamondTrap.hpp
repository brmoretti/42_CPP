/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:14:10 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 18:01:38 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
public:
	DiamondTrap();
	DiamondTrap(const std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap & rhs);
	DiamondTrap&	operator=(const DiamondTrap & rhs);

	void	attack(const std::string& target);
	void	whoAmI();

private:
	std::string const	_name;
};

#endif
