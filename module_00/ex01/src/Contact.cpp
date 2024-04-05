/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoretti < bmoretti@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 12:47:58 by bmoretti          #+#    #+#             */
/*   Updated: 2024/04/05 10:19:17 by bmoretti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact( void )
{	
}

Contact::~Contact( void )
{	
}

std::string	Contact::get_property( contact_prop property ) const
{
	switch (property) {
	case FIRST_NAME:
		return this->_first_name;
	case LAST_NAME:
		return this->_last_name;
	case NICKNAME:
		return this->_nickname;
	case PHONE_NUMBER:
		return this->_phone_number;
	case DARK_SECRET:
		return this->_darkest_secret;
	default:
		std::cerr << "Invalid property" << std::endl;
		return NULL;
	}
}

bool		Contact::set_property( std::string str, contact_prop property )
{
	if (str.length() == 0) {
		std::cerr << "❌ Empty field not allowed" << std::endl;
		return false;
	}
	switch (property) {
	case FIRST_NAME:
		this->_first_name = str;
		return true;
	case LAST_NAME:
		this->_last_name = str;
		return true;
	case NICKNAME:
		this->_nickname = str;
		return true;
	case PHONE_NUMBER:
		if (Contact::_valid_phone_number(str)) {
			this->_phone_number = str;
			return true;
		} else
			return false;
	case DARK_SECRET:
		this->_darkest_secret = str;
		return true;
	default:
		std::cerr << "❌ Invalid property" << std::endl;
		return false;
	}
}

bool		Contact::_valid_phone_number( std::string phone_number ) const
{
	for (std::string::size_type i = 0; i < phone_number.length(); i++) {
		char c = phone_number[i];
		if (!isdigit(c) && c != '(' && c != ')' && c != '-' && c != '+' && c != ' ') {
			std::cerr << "❌ Invalid character" << std::endl;
			return false;
		}
	}
	if (phone_number.length() > 20) {
		std::cerr << "❌ Phone number can have up to 20 characters" << std::endl;
		return false;
	}
	return true;
}

void	Contact::print_contact_info( void ) const
{
	std::cout << "First name:\t" << this->_first_name << "\n";
	std::cout << "Last name:\t" << this->_last_name << "\n";
	std::cout << "Nickame:\t" << this->_nickname << "\n";
	std::cout << "Phone number:\t" << this->_phone_number << "\n";
	std::cout << "Darkest Secret:\t" << this->_darkest_secret << "\n";
	std::cout << std::endl;
}
