/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:13:04 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/11 18:01:15 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

typedef enum {
	IS_OK,
	IS_DEAD,
	IS_EXAUSTED
}	player_status;

class ClapTrap
{
public:
	ClapTrap( std::string name );
	~ClapTrap();
	ClapTrap(const ClapTrap & rhs);
	ClapTrap&	operator=(const ClapTrap & rhs);
	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

private:
	std::string		_name;
	int				_hit_points;
	int				_energy_points;
	int				_attack_damage;
	player_status	_getPlayerStatus( void );
	void			_cantDoMsg( std::string action, player_status status );
};

#endif
