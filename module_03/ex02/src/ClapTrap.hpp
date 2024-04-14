/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:13:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/14 17:20:59 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(const std::string name);
	~ClapTrap();
	ClapTrap(const ClapTrap & rhs);
	ClapTrap&	operator=(const ClapTrap & rhs);
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);
	std::string	getName(void) const;
	int			getHitPoints(void) const;
	int			getEnergyPoints(void) const;
	int			getAttackDamage(void) const;
	void		setAttackDamage(int attack_damage);

protected:
	std::string const	_name;
	int					_hit_points;
	int					_energy_points;
	int					_attack_damage;
	bool				_isDead();
	bool				_isExausted();
	bool				_isOk();

private:
	const static int	HIT_POINTS = 10;
	const static int	ENERGY_POINTS = 10;
	const static int	ATTACK_DAMAGE = 0;
};

#endif
