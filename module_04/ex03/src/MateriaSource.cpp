/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:08:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 17:49:26 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _n_learned_materias(0)
{
	std::cout << "Materia constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia destructor called" << std::endl;
	for (int i = 0; i < this->_n_learned_materias; i++) {
		delete this->_learned_materias[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource & rhs)
{
	std::cout << "Materia copy constructor called" << std::endl;
	*this = rhs;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource & rhs)
{
	std::cout << "Materia '=' operator overload called" << std::endl;
	this->_n_learned_materias = rhs._n_learned_materias;
	for (int i = 0; i < this->_n_learned_materias; i++) {
		this->_learned_materias[i] = rhs._learned_materias[i]->clone();
	}
}

//IMateriaSource
void		MateriaSource::learnMateria(AMateria *materia)
{
	if (this->_n_learned_materias < MAX_LEARNED_MATERIAS) {
		this->_learned_materias[_n_learned_materias] = materia;
		std::cout << materia->getType();
		std::cout << " learned. (Slot " << this->_n_learned_materias++ << ")";
		std::cout << std::endl;
		return;
	}
	std::cout << "Materia Source is full. Unable to learn anymore." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string materia_type)
{
	for (int i = 0; i < this->_n_learned_materias; i++) {
		if (!this->_learned_materias[i]->getType().compare(materia_type)) {
			std::cout << "Materia cloned" << std::endl;
			return this->_learned_materias[i]->clone();
		}
	}
	std::cout << "Clone failed. Unknown type of Materia" << std::endl;
}
