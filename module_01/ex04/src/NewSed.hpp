/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 01:44:05 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/06 14:01:33 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEWSED_HPP
# define NEWSED_HPP

# include "SedIsForLosers.hpp"

class NewSed
{
private:
	std::fstream	_input;
	std::fstream	_output;
	void			_replacing( const std::string& s1, const std::string& s2 );

public:
	NewSed( const std::string& input_file, const std::string& s1,
		 const std::string& s2 );
	~NewSed( void );
};

#endif
