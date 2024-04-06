/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NewSed.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:23:22 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/06 14:37:08 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NewSed.hpp"

NewSed::NewSed( const std::string& input_file, const std::string& s1,
		 const std::string& s2 )
{
	this->_input.open(input_file.c_str(), std::fstream::in);
	if (this->_input.fail()) {
		std::cerr << "Error opening the input file" << std::endl;
		return ;
	}
	std::string 	out_name = input_file + ".replace";
	this->_output.open(out_name.c_str(), std::fstream::out
		 | std::fstream::trunc);
	if (this->_output.fail()) {
		std::cerr << "Cannot open the output file" << std::endl;
		this->_input.close();
		return ;
	}
	this->_replacing(s1, s2);
	this->_input.close();
	this->_output.close();
}

NewSed::~NewSed( void )
{
}

void	NewSed::_replacing( const std::string& s1, const std::string& s2 )
{
	std::string	line;
	std::string	new_line;

	while (std::getline(this->_input, line)) {
		new_line = replaceSubstring(line, s1, s2);
		this->_output << new_line << std::endl;
	}
}
