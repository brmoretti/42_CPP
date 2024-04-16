/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti <bmoretti@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:33:32 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/16 17:52:46 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

# define N_IDEAS 100

class Brain
{
public:
	Brain();
	~Brain();
	Brain(const Brain & rhs);
	Brain&	operator=(const Brain & rhs);

	const std::string	getIdea(const int & idea_index) const;
	void				setIdea(const int & idea_index, const std::string & idea);

private:
	std::string	_ideas[N_IDEAS];
};

#endif
