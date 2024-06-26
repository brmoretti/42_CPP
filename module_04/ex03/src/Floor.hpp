/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:57:00 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 15:18:37 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

# include "DefineColors.hpp"

# include "AMateria.hpp"

class Floor
{
public:
	Floor();
	~Floor();
	Floor(const Floor & rhs);
	Floor&	operator=(const Floor & rhs);

	bool		drop(AMateria *m);

private:
	AMateria*	_spaces[10];
	void		clearFloorItems();
	void		cloneFloorItems(const Floor & floor);
};

#endif
