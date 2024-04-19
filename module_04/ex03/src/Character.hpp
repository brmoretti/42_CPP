/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:51:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/18 16:32:49 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Floor.hpp"

class Character : public ICharacter
{
public:
	Character(const std::string name);
	~Character();
	Character(const Character & rhs);
	Character&	operator=(const Character & rhs);

	//ICharacter
	std::string const &	getName() const;
	void				equip(AMateria* m);
	void				unequip(int idx);
	void				use(int idx, ICharacter& target);

	void				setFloor(Floor* floor);
	Floor*				getFloor() const;

private:
	std::string			_name;
	AMateria*			_inventory[4];
	Floor*				_floor;
	
	void	clearInventory();
	void	cloneInventory(const Character & character);
};

#endif
