/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:49:53 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/17 11:55:29 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal
{
public:
	Cat();
	~Cat();
	Cat(const Cat & rhs);
	Cat&	operator=(const Cat & rhs);

	void	makeSound() const;
	Brain*	accessBrain() const;

private:
	Brain*	_brain;
};

#endif
