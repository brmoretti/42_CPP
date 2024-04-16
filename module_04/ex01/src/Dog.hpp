/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 18:15:21 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
public:
	Dog();
	~Dog();
	Dog(const Dog & rhs);
	Dog&	operator=(const Dog & rhs);

	void	makeSound() const;
	Brain*	accessBrain() const;

private:
	Brain*	_brain;
};

#endif
