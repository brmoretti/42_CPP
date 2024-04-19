/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:06:20 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/19 19:05:14 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

#define MAX_LEARNED_MATERIAS 4

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource & rhs);
	MateriaSource&	operator=(const MateriaSource & rhs);

	//IMateriaSource
	void		learnMateria(AMateria *materia);
	AMateria*	createMateria(std::string materia_type);

private:
	AMateria*	_learned_materias[4];
	int			_n_learned_materias;

	void		clearMaterias();
	void		cloneMaterias(const MateriaSource & m_source);
};

#endif
