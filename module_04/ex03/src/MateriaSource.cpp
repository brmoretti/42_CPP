/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:08:13 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/22 13:33:22 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : _n_learned_materias(0)
{
	std::cout << "Materia constructor called" << std::endl;
	for (int i = 0; i < 4; i++) {
		this->_learned_materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "Materia destructor called" << std::endl;
	this->clearMaterias();
}

MateriaSource::MateriaSource(const MateriaSource & rhs)
{
	std::cout << "Materia copy constructor called" << std::endl;
	*this = rhs;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource & rhs)
{
	std::cout << "Materia '=' operator overload called" << std::endl;
	if (this != &rhs) {
		this->clearMaterias();
		this->cloneMaterias(rhs);
	}
	return *this;
}

//IMateriaSource
void		MateriaSource::learnMateria(AMateria *materia)
{
	if (this->_n_learned_materias < MAX_LEARNED_MATERIAS) {
		this->_learned_materias[_n_learned_materias] = materia;
		std::cout << BG_CYAN(materia->getType();
		std::cout << " learned. (Slot " << this->_n_learned_materias++ << ")");
		std::cout << std::endl;
		return;
	}
	std::cout << "Materia Source is full. Unable to learn anymore." << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string materia_type)
{
	for (int i = 0; i < this->_n_learned_materias; i++) {
		if (!this->_learned_materias[i]->getType().compare(materia_type)) {
			std::cout << BG_CYAN("Materia cloned") << std::endl;
			return this->_learned_materias[i]->clone();
		}
	}
	std::cout << BG_CYAN("Clone failed. Unknown type of Materia " << materia_type);
	std::cout << std::endl;
	return NULL;
}

void	MateriaSource::clearMaterias()
{
	for (int i = 0; i < 4; i++) {
		if (this->_learned_materias[i]) {
			delete this->_learned_materias[i];
			this->_learned_materias[i] = NULL;
		}
	}
}

void	MateriaSource::cloneMaterias(const MateriaSource & m_source)
{
	this->clearMaterias();
	for (int i = 0; i < 4; i++) {
		if (m_source._learned_materias[i]) {
			this->_learned_materias[i] =
				m_source._learned_materias[i]->clone();
		}
	}
}
